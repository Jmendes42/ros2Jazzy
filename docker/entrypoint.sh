#!/bin/bash
set -e

echo "alias build=\"cd /home/void/ros2_ws && colcon build && source ~/.bashrc\"" >> /home/void/.bashrc
echo "alias mycobot=\"bash ~/ros2_ws/src/mycobot_ros2/mycobot_bringup/scripts/mycobot_280_gazebo.sh\"" >> /home/void/.bashrc
echo "alias x3=\"bash ~/ros2_ws/src/yahboom_rosmaster/yahboom_rosmaster_bringup/scripts/rosmaster_x3_gazebo.sh\"" >> /home/void/.bashrc

echo "export GZ_SIM_RESOURCE_PATH=/home/void/ros2_ws/src/mycobot_ros2/mycobot_gazebo/models" >> /home/void/.bashrc
echo "export GZ_SIM_RESOURCE_PATH=/home/void/ros2_ws/src/yahboom_rosmaster/yahboom_rosmaster_gazebo/models" >> /home/void/.bashrc

exec "$@"