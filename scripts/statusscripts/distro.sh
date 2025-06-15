#!/bin/bash

distro=$(grep -E '^ID=' /etc/os-release | cut -d= -f2 | tr -d '"')

case "$distro" in
void)
  icon=""
  ;;
arch)
  icon="󰣇"
  ;;
debian)
  icon=""
  ;;
gentoo)
  icon=""
  ;;
*)
  icon=""
  ;;
esac

echo $icon
