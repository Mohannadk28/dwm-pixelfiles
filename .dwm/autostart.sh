#!/bin/bash

amixer set Master 100%
brightnessctl s 100%

mpv --no-video ~/.pixelfiles/sounds-pixelfiles/startup.mp3 &

/usr/bin/lxpolkit & # LX PolicyKit
#feh --no-fehbg --bg-fill -z ~/.pixelfiles/wallpapers-pixelfiles/* # Sets The Wallpaper
wal -i "/home/mohannadk28/.pixelfiles/wallpapers-pixelfiles/wallhaven-mdr8o1.jpg"
dwmblocks & # Starts DWM Blocks
emacs --daemon &

picom & # Starts The Composter
conky -c ~/.config/conky/conkyrc & # Starts The Weather Widget

megasync & # starts MEGAsync
syncthingtray & # Syncthing
keepassxc & # Password Manager


