import rclpy
from rclpy.node import Node
import serial
from sensor_msgs.msg import Range

class UltrasonicPublisher(Node):
    def __init__(self):
        super().__init__('ultrasonic_range_publisher')

        # Set up publishers for each direction
        self.pub_left = self.create_publisher(Range, 'ultrasonic/left', 10)
        self.pub_front = self.create_publisher(Range, 'ultrasonic/front', 10)
        self.pub_right = self.create_publisher(Range, 'ultrasonic/right', 10)

        # Set up serial connection
        self.ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)

        # Set up timer to read data regularly
        self.timer = self.create_timer(0.1, self.read_serial_data)

        # Sensor parameters
        self.min_range_m = 0.10     # 10 cm
        self.max_range_m = 1.95     # 195 cm
        self.fov_rad = 0.2618       # 15° in rad

    def read_serial_data(self):
        try:
            line = self.ser.readline().decode('utf-8').strip()
            values = [float(x) for x in line.split(',')]

            if len(values) != 3:
                self.get_logger().warn('Unerwartetes Format: ' + line)
                return

            self.publish_range(self.pub_left, values[0], 'ultrasonic_left')
            self.publish_range(self.pub_front, values[1], 'ultrasonic_front')
            self.publish_range(self.pub_right, values[2], 'ultrasonic_right')

        except Exception as e:
            self.get_logger().error(f'Fehler beim Lesen der seriellen Daten: {e}')

    def publish_range(self, publisher, cm_value, frame_id):
        msg = Range()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = frame_id

        msg.radiation_type = Range.ULTRASOUND
        msg.field_of_view = self.fov_rad
        msg.min_range = self.min_range_m
        msg.max_range = self.max_range_m

        range_m = cm_value / 100.0
        if self.min_range_m <= range_m <= self.max_range_m:
            msg.range = range_m
        else:
            msg.range = float('nan')  # ungültige Messung

        publisher.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = UltrasonicPublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

