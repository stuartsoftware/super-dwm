#!/bin/bash
while true; do
	# Obtener datos
	TIME=$(date "+%I:%M")
	DATE=$(date "+%d-%m-%y")
	
	
	TEMP=$(cat /sys/class/thermal/thermal_zone0/temp)
	TEMP_C=$(awk "BEGIN {printf \"%.1f°C\", $TEMP/1000}")
	MEM=$(free -m | awk 'NR==2{print $3}')

	# Mostrar datos (utiliza xsetroot)
	xsetroot -name "  $TEMP_C |  ${MEM}MB |  $DATE | 󰥔 $TIME "
	sleep 5
done
	
