#!/bin/bash

# Path to the folder
folder_path="C:/Users/saksh/OneDrive/Desktop/github/Finishing-Leetcode"

# Ensure the folder exists
if [ ! -d "$folder_path" ]; then
    echo "Error: Folder path '$folder_path' does not exist"
    exit 1
fi

# Loop through folders and rename
for ((i=306; i<=701; i++)); do
    folder_name=$(printf "%04d-" "$i")  # Pad the number with zeros
    if [ -d "$folder_path/$folder_name" ]; then
        new_name="0${folder_name%-*}${folder_name#*-}"  # Add a "0" before the folder name and remove the last hyphen
        mv "$folder_path/$folder_name" "$folder_path/$new_name"
        echo "Renamed: $folder_name to $new_name"
    else
        echo "Folder not found: $folder_path/$folder_name"
    fi
done