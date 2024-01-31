#!/bin/bash

# Set the source folder path
source_folder="/c/Users/saksh/OneDrive/Desktop/github/Finishing-Leetcode/Finishing-Leetcode"

# Set the destination folder path
destination_folder="/c/Users/saksh/OneDrive/Desktop/github/Finishing-Leetcode/"

# Loop through all sub-folders in the source folder
for folder in "$source_folder"/*/; do
    # Extract the folder name
    folder_name=$(basename "$folder")

    # Set the destination folder path for the current sub-folder
    destination_folder_name="${destination_folder}${folder_name}"

    # Move the sub-folder to the destination folder
    mv "$folder" "$destination_folder_name"

    echo "Moved $folder to $destination_folder_name"
done
