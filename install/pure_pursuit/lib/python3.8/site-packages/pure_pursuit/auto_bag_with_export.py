import os
import subprocess
import signal
import time
import sqlite3
import rclpy
from rclpy.node import Node
from std_msgs.msg import Bool
from rclpy.serialization import deserialize_message
from nav_msgs.msg import OccupancyGrid
from visualization_msgs.msg import MarkerArray
from scipy.io import savemat
import numpy as np

SAVE_DIR = os.path.expanduser('~/shared/temp')
os.makedirs(SAVE_DIR, exist_ok=True)

class TrajectoryRecorder(Node):
    def __init__(self):
        super().__init__('trajectory_recorder')
        self.recording = False
        self.record_count = 0
        self.trajectory_proc = None
        self.map_time_tag = ''
        self.traj_time_tag = ''

        self.create_subscription(Bool, '/is_recording_Traj', self.recording_callback, 10)

        # 启动时自动开始记录 map
        self.start_map_bag()

    def start_map_bag(self):
        self.map_time_tag = time.strftime("%Y%m%d_%H%M%S")
        map_folder = os.path.join(SAVE_DIR, f'map_{self.map_time_tag}')
        self.get_logger().info(f'🟢 开始记录 /map 到 {map_folder}')
        subprocess.Popen([
            'ros2', 'bag', 'record', '/map',
            '--output', map_folder
        ])

    def recording_callback(self, msg: Bool):
        if msg.data and not self.recording:
            self.start_trajectory_bag()
        elif not msg.data and self.recording:
            self.stop_trajectory_bag()

    def start_trajectory_bag(self):
        self.traj_time_tag = time.strftime("%Y%m%d_%H%M%S")
        traj_folder = os.path.join(SAVE_DIR, f'trajectory_{self.traj_time_tag}')
        self.get_logger().info(f'🟢 开始记录 /trajectory_node_list 到 {traj_folder}')
        self.trajectory_proc = subprocess.Popen([
            'ros2', 'bag', 'record', '/trajectory_node_list',
            '--output', traj_folder
        ])
        self.recording = True

    def stop_trajectory_bag(self):
        if self.trajectory_proc:
            self.get_logger().info(f'🛑 停止记录 trajectory_{self.traj_time_tag}')
            self.trajectory_proc.send_signal(signal.SIGINT)
            self.trajectory_proc.wait()
            time.sleep(1)
            self.export_trajectory_to_txt()
            self.record_count += 1
            self.trajectory_proc = None
        self.recording = False

    def destroy_node(self):
        self.get_logger().info('🛑 退出节点，导出地图为 .mat 文件...')
        try:
            self.export_map_to_mat()
        except Exception as e:
            self.get_logger().error(f'❌ 地图导出失败：{e}')
        super().destroy_node()

    def export_map_to_mat(self):
        # 使用带 _0 的文件夹，因为 ros2 bag 会自动加后缀
        folder = os.path.join(SAVE_DIR, f'map_{self.map_time_tag}')
        db3_path = os.path.join(folder, f'map_{self.map_time_tag}_0.db3')

        if not os.path.exists(db3_path):
            self.get_logger().warning(f'⚠️ 地图 bag 数据库文件不存在：{db3_path}')
            return

        conn = sqlite3.connect(db3_path)
        cursor = conn.cursor()

        cursor.execute("SELECT id, name FROM topics")
        topic_dict = dict(cursor.fetchall())

        cursor.execute("SELECT topic_id, timestamp, data FROM messages")
        rows = cursor.fetchall()

        map_msgs = []
        for topic_id, timestamp, data in rows:
            if topic_dict.get(topic_id, "") == '/map':
                try:
                    msg = deserialize_message(data, OccupancyGrid)
                    map_msgs.append(msg)
                except Exception as e:
                    self.get_logger().warning(f"❌ 地图解析失败: {e}")

        if not map_msgs:
            self.get_logger().warning('⚠️ 没有找到任何 /map 消息')
            return

        last = map_msgs[-1]
        map_array = np.array(last.data).reshape((last.info.height, last.info.width))
        # 固定文件名
        mat_path = os.path.join(folder, 'map_data.mat')
        savemat(mat_path, {
            'data': map_array,
            'width': last.info.width,
            'height': last.info.height,
            'resolution': last.info.resolution,
            'origin_x': last.info.origin.position.x,
            'origin_y': last.info.origin.position.y
        })
        self.get_logger().info(f'✅ 地图已保存为 {mat_path}')

    def export_trajectory_to_txt(self):
        
        folder = os.path.join(SAVE_DIR, f'trajectory_{self.traj_time_tag}')
        db_path = os.path.join(folder, f'trajectory_{self.traj_time_tag}_0.db3')

        if not os.path.exists(db_path):
            self.get_logger().warning(f'⚠️ 轨迹 bag 数据库文件不存在：{db_path}')
            return

        conn = sqlite3.connect(db_path)
        cursor = conn.cursor()

        cursor.execute("SELECT id, name FROM topics")
        topic_dict = dict(cursor.fetchall())

        cursor.execute("SELECT topic_id, timestamp, data FROM messages")
        rows = cursor.fetchall()

        traj_msgs = []
        for topic_id, timestamp, data in rows:
            if topic_dict.get(topic_id, "") == '/trajectory_node_list':
                try:
                    msg = deserialize_message(data, MarkerArray)
                    traj_msgs.append(msg)
                except Exception as e:
                    self.get_logger().warning(f"❌ 轨迹解析失败: {e}")

        if not traj_msgs:
            self.get_logger().warning('⚠️ 没有找到任何轨迹消息')
            return

        # 固定文件名
        txt_path = os.path.join(folder, 'trajectory.txt')
        with open(txt_path, "w") as f:
            for marker_array in traj_msgs:
                for marker in marker_array.markers:
                    if marker.type == marker.LINE_STRIP:
                        for pt in marker.points:
                            f.write(f"{pt.x},{pt.y}\n")
        self.get_logger().info(f'✅ 轨迹已保存到 {txt_path}')


def main(args=None):
    rclpy.init(args=args)
    node = TrajectoryRecorder()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
