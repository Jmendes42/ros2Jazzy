#!/bin/bash
set -e

echo "export GZ_SIM_RESOURCE_PATH=/home/void/ros2_ws/src/mycobot/mycobot_gazebo/models" >> /home/void/.bashrc
echo "alias build=\"cd /home/void/ros2_ws && colcon build\"" >> /home/void/.bashrc
echo "alias mycobot=\"bash ~/ros2_ws/src/mycobot_ros2/mycobot_bringup/scripts/mycobot_280_gazebo.sh\"" >> /home/void/.bashrc

exec "$@"