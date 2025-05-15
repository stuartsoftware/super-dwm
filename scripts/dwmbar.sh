#!/bin/bash

pggrep -x -u "$USER" dwmbar.sh > /dev/null && exit

while true; do  

	# Obtener datos
	TIME=$(date "+%I:%M")
	DATE=$(date "+%d-%m-%y")
	
	# Capturar datos especificos 
	MEM=$(free -m | awk 'NR==2{print $3}')
	
	# Mostrar datos (utiliza xsetroot)
	xsetroot -name "  ${MEM}MB |  $DATE | 󰥔 $TIME " 2>/dev/null  
	sleep 5
done
	
