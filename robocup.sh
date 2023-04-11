#!/bin/bash
cd /home/pi/work/maze_bot/programming/mbot_ws
source /opt/ros/humble/setup.bash
colcon build 
source install/setup.bash
ros2 launch robocup robocup.launch.py