#!/bin/bash

DIR="$HOME/.config/super-dwm/scripts"

xsetroot -name " you're using super-dwm a config by @stuartsoftware "
sleep 2

while true; do
  # date
  TIME=$($DIR/clock.sh)
  DATE=$($DIR/date.sh)
  RAM=$($DIR/ram.sh)
  TEMP=$($DIR/temp.sh)

  # linux distro used...

  DISTRO=$(grep -E '^ID=' /etc/os-release | cut -d= -f2 | tr -d '"')
  case "$DISTRO" in
  void)
    icon=""
    ;;
  arch)
    icon="󰣇"
    ;;
  debian)
    icon=""
    ;;
  *)
    icon=""
    ;;
  esac

  # show data with xsetroot

  xsetroot -name " [ $TEMP < $RAM ] • $DATE • $TIME • $icon "
  sleep 1
done
