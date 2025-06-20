#!/bin/bash

echo -e "
super-dwm help
Hi, it seems that you pressed super + f1
These are the hotkeys of this dwm config
"

sleep 2

echo "REMEMBER YOU CAN MODIFY THIS, JUST CHANGE WHATEVER YOU WANT IN CONFIG.H in your super-dwm folder
DON'T BE SHY do it :), IF IT BREAKS, YOUR LEARN MORE THAT WAY"

sleep 1

echo -e "

super is the windows key... 

*** PROGRAMS ***
super + e = Thunar
super + d = rofi
super + v = pavucontrol
super + p = xfce4-screenshooter
super + enter = terminal emulator (ALACRITTY)

*** DWM HOTKEYS ***

super + j && super + k = CHANGE WINDOW FOCUS (looks another window)
super + h && super + l = CHANGE INCH OF MASTER WINDOW
super + b = hide status bar

super + numbers = you change between workspaces (there are 9)
super + t = tile mode 
super + f = floating mode 
super + m = monocle mode (I recommend use super + shift + f)
super + shift + q = close window

super + , = change focus to ANOTHER MONITOR
super + . = the same but another way 

super + shift + esc = QUIT DWM (logout you go back to dm or tty)

super + F11 && super + F12 = brightness (brightnessctl)


if you don't use alacritty you can see this help in super-dwm folder, as superhelp.sh
super-dwm it's just a minimal config of dwm
https://github.com/stuartsoftware/super-dwm
"

read -p "Press any key to close..."
