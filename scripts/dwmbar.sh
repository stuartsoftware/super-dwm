#!/bin/bash
while true; do
	# Obtener datos
	TIME=$(date "+%I:%M")
	DATE=$(date "+%d-%m-%y")
	TEMP=$(cat /sys/class/thermal/thermal_zone0/temp)
	
	# Capturar datos especificos 
	TEMP_C=$(awk "BEGIN {printf \"%.1f°C\", $TEMP/1000}")
	MEM=$(free -m | awk 'NR==2{print $3}')
	DISK_USED=$(df -h | awk 'NR==4{print $3}') # sda2
	DISK_FREE=$(df -h | awk 'NR==4{print $4}') # sda2
	
	# Mostrar datos (utiliza xsetroot)
	xsetroot -name "  $TEMP_C | 󰋊 $DISK_USED/$DISK_FREE |  ${MEM}MB |  $DATE | 󰥔 $TIME "
	sleep 5
done
	
