#!/bin/bash

# Terminal 1
gnome-terminal -- bash -c "
    source ~/ws/install/setup.bash;
    export TURTLEBOT3_MODEL=burger;
    export GAZEBO_MODEL_PATH=\$(ros2 pkg prefix turtlebot3_gazebo)/share/turtlebot3_gazebo/models/;
    ros2 launch turtlebot3_gazebo turtlebot3_world.launch.py;
    exec bash
"

# Terminal 2
#gnome-terminal -- bash -c "
    #source ~/ws/install/setup.bash;
    #export TURTLEBOT3_MODEL=burger;
    #ros2 run teleop_with_emergency_stop teleop_with_emergency_stop;
    #exec bash
#"

# Terminal 3
gnome-terminal -- bash -c "
    source ~/ws/install/setup.bash;
    export TURTLEBOT3_MODEL=burger;
    ros2 run turtlebot3_teleop teleop_keyboard;
    exec bash
"

# Terminal 4
gnome-terminal -- bash -c "
    source ~/SA_CAO/install/setup.bash;
    ros2 run joy joy_node
    
    exec bash
    "
    # Terminal 5
gnome-terminal -- bash -c "
    source ~/SA_CAO/install/setup.bash;
    ros2 run my_xbox_joystick xbox_joystick
    exec bash
    "
        # Terminal 6
gnome-terminal -- bash -c "
    source ~/SA_CAO/install/setup.bash;
    export RMW_IMPLEMENTATION=rmw_cyclonedds_cpp
    ros2 run sub_diablo Sub_diablo
    exec bash
    "
    
            # Terminal 7
gnome-terminal -- bash -c "
    source ~/SA_CAO/install/setup.bash;
    export RMW_IMPLEMENTATION=rmw_cyclonedds_cpp
    ros2 run cmd_vel2motionctrl cmd_vel2motionctrl
    exec bash
    "
