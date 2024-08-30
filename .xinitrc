#!/bin/sh

slstatus &
dunst &
xwallpaper --zoom ~/Pictures/Wallpapers/grayscale/gray_city.jpeg &

while type dwm >/dev/null; do dwm && continue || break;done
