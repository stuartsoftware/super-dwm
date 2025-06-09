#!/bin/bash

ram="$(free -m | awk '/^Mem/ { print $3"MB" }' | sed s/i//g)"
ram_icon=""
ram_format=" $ram_icon $ram "
echo $ram_format
