#!/bin/bash

# This script is made to open a new terminal with two tabs for
# the math container.
# It's made to work with the terminator terminal and uses the
# xdotool to manipulate terminal commands

# sudo apt install terminator
# sudo apt install xdotool

set -e

CONTAINER_NAME="jazzy-dev"
IMAGE_NAME="jazzy-dev"
WORKSPACE_DIR="$PWD/ros2_ws"

if [ "$(docker ps -q -f name=^/${CONTAINER_NAME}$)" ]; then
    echo "Container ${CONTAINER_NAME} is already running."
else
  docker run -itd --rm \
    --user void \
    --network=host \
    --ipc=host \
    -v "$WORKSPACE_DIR":/home/void/ros2_ws \
    -v /tmp/.X11-unix:/tmp/.X11-unix:rw \
    --env=DISPLAY \
    --name $CONTAINER_NAME \
    $IMAGE_NAME
fi

# Wait for the container to initialize
sleep 1

xdotool key ctrl+shift+e
sleep 0.1
xdotool type "docker exec -it $CONTAINER_NAME bash -c 'source /opt/ros/jazzy/setup.bash; [ -f /ws/install/setup.bash ] && source /ws/install/setup.bash; exec bash'"
xdotool key Return

xdotool key ctrl+shift+o
sleep 0.1
xdotool type "docker exec -it $CONTAINER_NAME bash -c 'source /opt/ros/jazzy/setup.bash; [ -f /ws/install/setup.bash ] && source /ws/install/setup.bash; exec bash'"
xdotool key Return