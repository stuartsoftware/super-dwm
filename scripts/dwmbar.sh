#!/bin/bash

while true; do

  # Obtener fecha y hora
  TIME=$(date "+%I:%M")
  DATE=$(date "+%d-%m-%y")

  # Obtain hardware information
  MEM=$(free -m | awk 'NR==2{print $3}')
  CPU=$()

  # Esto es para el icono de la distro que este usando...

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
  gentoo)
    icon=""
    ;;
  *)
    icon = ""
    ;;
  esac

  # Mostrar datos (utiliza xsetroot)
  xsetroot -name " ${MEM}MB •  $DATE • 󰥔 $TIME • $icon  ~  " 0>/dev/null
  sleep 5

done
