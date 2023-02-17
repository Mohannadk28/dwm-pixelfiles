#!/bin/bash

amixer set Master 100%
brightnessctl s 100%

mpv --no-video ~/.pixelfiles/sounds-pixelfiles/startup.mp3 &

/usr/bin/lxpolkit & # LX PolicyKit
feh --bg-fill -z ~/.wallpapers/* # Sets The Wallpaper
dwmblocks & # Starts DWM Blocks
emacs --daemon &

picom & # Starts The Composter
conky & # Starts The Weather Widget

megasync & # starts MEGAsync
syncthingtray & # Syncthing
keepassxc & # Password Manager


