!/bin/sh

sudo make clean install
sudo make clean

exec ./statusbar_install.sh &
cp ./superhelp.sh ~/.config/super-dwm/scripts/
chmod +x ~/.config/super-dwm/scripts/superhelp.sh # just in case
