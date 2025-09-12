#!/bin/bash
set -e

if [ -f /ws/install/setup.bash ]; then
    source /ws/install/setup.bash
fi

exec bash
echo "export RMW_IMPLEMENTATION=rmw-cyclonedds-cpp" >> /home/void/.bashrc

