#!/bin/bash

mkdir -p $HOME/.config/super-dwm/scripts
cp -r ./scripts/*.* $HOME/.config/super-dwm/scripts
cp -r ./scripts/statusscripts/*.* $HOME/.config/super-dwm/scripts
chmod +x $HOME/.config/super-dwm/scripts/*.*

if [ -f $HOME/.config/super-dwm/scripts/statusbar.sh ]; then
  echo "statusbar.sh updated!"
  pkill statusbar.sh
  exec $HOME/.config/super-dwm/scripts/statusbar.sh &
fi

if [ -f $HOME/.xsession ]; then
  echo -e "Did you update your .x file?, don't forget to update your .xsession\nput this -> '~/.config/super-dwm/scripts/statusbar.sh &' before dwm"
fi

if [ -f $HOME/.xinitrc ]; then
  echo -e "Did you update your .x file?, don't forget to update your .xinitrc\nput this -> '~/.config/super-dwm/scripts/statusbar.sh &' before dwm"
fi
