#!/bin/bash

# Get screen dimensions using xdpyinfo
screen_dimensions=$(xdpyinfo | grep dimensions)
screen_width=$(echo "$screen_dimensions" | awk '{print $2}' | cut -d 'x' -f1)
screen_height=$(echo "$screen_dimensions" | awk '{print $2}' | cut -d 'x' -f2)

echo "Screen dimensions: ${screen_width}x${screen_height}"

