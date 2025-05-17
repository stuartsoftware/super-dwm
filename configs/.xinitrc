#!bin/sh

exec dunst &
exec redshift -O 4900 &
exec xrandr -r 75 &
exec picom -I 0.1 -O 0.1 &
exec nitrogen --restore & 
exec /usr/lib/xdg-desktop-portal-gtk &
exec /usr/lib/xdg-desktop-portal &
exec dunstify "WM initiziated" "super-dwm a config by stuartsoftware" &
exec dwmbar.sh &
exec dwm 
