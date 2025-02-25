mkdir controller_ws
cd controller_ws
mkdir src
cd src
ros2 pkg create my_xbox_joystick --build-type ament_python --dependencies rclpy sensor_msgs std_srvs
cd my_xbox_joystick
cd my_xbox_joystick
touch xbox_joystick_node.py
vim xbox_joystick_node.py
----code----

cd ..
chmod +x my_xbox_joystick/xbox_joystick_node.py
vim setup.py
---code---

cd /root/controller_ws
colcon build
source install/setup.bash

ros2 run joy joy_node
ros2 run my_xbox_joystick xbox_joystick




sudo systemctl status bluetooth
sudo systemctl start bluetooth
sudo systemctl enable bluetooth #开机自动启动

bluetoothctl
power on          # 开启蓝牙
agent on          # 启用代理
scan on           # 开始扫描蓝牙设备
---
[NEW] Device XX:XX:XX:XX:XX:XX Wireless Controller

pair XX:XX:XX:XX:XX:XX
---
Pairing successful

trust XX:XX:XX:XX:XX:XX
connect XX:XX:XX:XX:XX:XX
---
Connection successful

exit

bluetoothctl connect XX:XX:XX:XX:XX:XX
