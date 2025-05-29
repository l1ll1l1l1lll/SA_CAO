import sqlite3
import rclpy
from rclpy.serialization import deserialize_message
from nav_msgs.msg import OccupancyGrid
from visualization_msgs.msg import MarkerArray
import numpy as np
from scipy.io import savemat

def main():
    rclpy.init()
    
    try:
        # 连接数据库
        conn = sqlite3.connect('my_bag_0.db3')
        cursor = conn.cursor()

        # 获取 topic ID 和名称映射
        cursor.execute("SELECT id, name FROM topics")
        topics = cursor.fetchall()
        topic_dict = {topic_id: name for topic_id, name in topics}

        # 获取所有消息
        cursor.execute("SELECT topic_id, timestamp, data FROM messages")
        rows = cursor.fetchall()

        map_msgs = []
        traj_msgs = []

        for topic_id, timestamp, data in rows:
            topic_name = topic_dict.get(topic_id, "")
            try:
                if topic_name == '/map':
                    msg = deserialize_message(data, OccupancyGrid)
                    map_msgs.append(msg)
                elif topic_name == '/trajectory_node_list':
                    msg = deserialize_message(data, MarkerArray)
                    traj_msgs.append(msg)
            except Exception as e:
                print(f"❌ 无法解析消息 {topic_name}：{e}")

        print(f"✅ 读取 {len(map_msgs)} 条 /map 消息")
        print(f"✅ 读取 {len(traj_msgs)} 条 /trajectory_node_list 消息")

        # 保存最后一帧地图为mat文件
        if map_msgs:
            last = map_msgs[-1]
            print(f"最后一帧地图尺寸: {last.info.width}x{last.info.height}")

            try:
                map_array = np.array(last.data).reshape((last.info.height, last.info.width))
                savemat('map_data.mat', {
                    'data': map_array,
                    'width': last.info.width,
                    'height': last.info.height,
                    'resolution': last.info.resolution,
                    'origin_x': last.info.origin.position.x,
                    'origin_y': last.info.origin.position.y
                })
                print("✅ 地图已保存为 map_data.mat")
            except Exception as e:
                print(f"❌ 地图保存失败：{e}")

        # 保存轨迹点
        if traj_msgs:
            try:
                with open("trajectory.txt", "w") as f:
                    for marker_array in traj_msgs:
                        for marker in marker_array.markers:
                            if marker.type == marker.LINE_STRIP:
                                for pt in marker.points:
                                    f.write(f"{pt.x},{pt.y}\n")
                print("✅ 轨迹已保存到 trajectory.txt")
            except Exception as e:
                print(f"❌ 保存轨迹失败：{e}")

    except Exception as e:
        print(f"❌ 数据库或消息读取失败：{e}")
    
    finally:
        rclpy.shutdown()

if __name__ == '__main__':
    main()
