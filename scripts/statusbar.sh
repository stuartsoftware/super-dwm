#!/bin/bash

DIR="$HOME/.config/super-dwm/scripts"

xsetroot -name " you're using super-dwm a config by @stuartsoftware "
sleep 2

while true; do
  # info
  TIME=$($DIR/clock.sh)
  DATE=$($DIR/date.sh)
  RAM=$($DIR/ram.sh)
  TEMP=$($DIR/temp.sh)
  DISTRO=$($DIR/distro.sh)

  # show data with xsetroot

  xsetroot -name " [ $TEMP < $RAM ] • $DATE • $TIME • $DISTRO "
  sleep 3
done
