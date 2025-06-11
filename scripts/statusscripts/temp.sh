#!/bin/bash

# This need lm_sensors to work!!

temp=$(sensors -u | grep "temp1_input" | awk 'NR==1{printf "%.1f", $2}')
temp_icon=""
temp_format="$temp_icon $temp°C"
echo $temp_format
