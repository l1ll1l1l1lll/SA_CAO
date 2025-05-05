import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Range
import serial
import threading


class UltrasonicPublisher(Node):
    def __init__(self):
        super().__init__('ultrasonic_range_publisher')

        # === Sensor-Konfiguration ===
        self.min_range_m = 0.10
        self.max_range_m = 2.50
        self.fov_rad = 0.2618  # 15°

        # === ROS2 Publisher ===
        self.pub_left = self.create_publisher(Range, 'ultrasonic/left', 10)
        self.pub_front = self.create_publisher(Range, 'ultrasonic/front', 10)
        self.pub_right = self.create_publisher(Range, 'ultrasonic/right', 10)

        # === Serielle Verbindung ===
        try:
            self.ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
            self.get_logger().info('Serielle Verbindung hergestellt.')
        except serial.SerialException as e:
            self.get_logger().error(f'Serielle Verbindung fehlgeschlagen: {e}')
            raise e

        # === Separater Thread liest kontinuierlich vom Arduino ===
        self.serial_thread = threading.Thread(target=self.read_serial_data_loop, daemon=True)
        self.serial_thread.start()

    def read_serial_data_loop(self):
        while rclpy.ok():
            try:
                line = self.ser.readline().decode('utf-8').strip()
                if not line:
                    continue

                values = [int(v) for v in line.strip().split('\t')]
                if len(values) != 3:
                    continue

                # Optional Logging
                self.get_logger().debug(
                    f'Eingangsdaten: L={values[0]}cm, V={values[1]}cm, R={values[2]}cm'
                )

                self.publish_range(self.pub_left, values[0], 'ultrasonic_left')
                self.publish_range(self.pub_front, values[1], 'ultrasonic_front')
                self.publish_range(self.pub_right, values[2], 'ultrasonic_right')

            except Exception as e:
                self.get_logger().error(f'Serienfehler: {e}')

    def publish_range(self, publisher, cm_value, frame_id):
        msg = Range()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = frame_id

        msg.radiation_type = Range.ULTRASOUND
        msg.field_of_view = self.fov_rad
        msg.min_range = self.min_range_m
        msg.max_range = self.max_range_m

        range_m = cm_value / 100.0
        msg.range = range_m if self.min_range_m <= range_m <= self.max_range_m else float('nan')

        publisher.publish(msg)


def main(args=None):
    rclpy.init(args=args)
    node = UltrasonicPublisher()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
