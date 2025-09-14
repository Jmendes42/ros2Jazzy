#!/bin/bash
set -e

echo "export GZ_SIM_RESOURCE_PATH=/home/void/ws/src/mycobot/mycobot_gazebo/models" >> /home/void/.bashrc
echo "alias build=\"cd /home/void/ws && colcon build\"" >> /home/void/.bashrc
echo "alias mycobot=\"bash ~/ws/src/mycobot/mycobot_bringup/scripts/mycobot_280_gazebo.sh\"" >> /home/void/.bashrc

exec "$@"