#!/bin/bash

# Define the path to the themes.txt file
themes_file="themes.txt"

# Check if the themes.txt file exists
if [[ ! -f $themes_file ]]; then
  echo "The themes file '$themes_file' does not exist."
  exit 1
fi

# Display available themes from the themes.txt file
echo "Available themes:"
mapfile -t theme_names < "$themes_file"  # Read all lines into an array
for theme_name in "${theme_names[@]}"; do
  echo "$theme_name"
done

# Prompt user for theme input
read -p "Enter the theme name: " theme_name

# Check if the chosen theme exists in the themes.txt file
if [[ ! " ${theme_names[*]} " =~ " ${theme_name} " ]]; then
  echo "Theme '$theme_name' not found in the themes file. Exiting."
  exit 1
fi

# List of directories to update
declare -a directories=("dmenu" "dwm" "slock" "slstatus" "st")

# Loop through each directory and update the config.h file
for dir in "${directories[@]}"; do
  config_file="$dir/config.h"

  if [[ -f $config_file ]]; then
    # Use sed to replace the theme in the #include line
    sed -i "s|#include[[:space:]]*\"themes/.*\.h\"|#include\"themes/${theme_name}.h\"|" "$config_file"
    echo "Updated theme in $config_file"
  else
    echo "Config file $config_file not found in $dir."
  fi
done

# Function to run make clean install in each directory
run_make() {
  local dir=$1
  cd "$dir" || exit
  sudo make clean install
  cd ..
}

# Run make clean install in each directory
for dir in "${directories[@]}"; do
  run_make "$dir"
done

echo "Theme applied and all programs rebuilt successfully."
