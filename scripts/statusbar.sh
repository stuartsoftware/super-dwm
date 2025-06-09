#!/bin/bash

DIR="$HOME/.config/super-dwm/scripts"

while true; do
  # date
  TIME=$($DIR/clock.sh)
  DATE=$($DIR/date.sh)
  RAM=$($DIR/ram.sh)

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

  xsetroot -name " $RAM • $DATE • $TIME • $icon "
  sleep 1
done
