#!/bin/bash


# Si tienes una interfaz diferente por la forma en la que se visualiza la hora y la fecha
# tendras que cambiar el nombre de la interfaz de red. Ej: eth0 == enp3s0
wifi=$(ip addr show wlan0 | grep 'inet ' | awk '{print $2}' | cut -d/ -f1)
eth=$(ip addr show enp3s0 | grep 'inet ' | awk '{print $2}' | cut -d/ -f1)

# Si no hay IP, mostrar "N/A"
[ -z "$wifi" ] && wifi="  " || wifi="   $wifi"
[ -z "$eth" ] && eth=" " || eth="  $eth"

echo "$wifi | $eth"
