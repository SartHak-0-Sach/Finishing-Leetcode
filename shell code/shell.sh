#!/bin/bash

# Parent directory path
parent_directory="C:/Users/saksh/OneDrive/Desktop/github/Finishing-Leetcode"

# Loop through each folder and clear contents of code.cpp and approach.txt
for folder in "$parent_directory"/*/; do
    if [ -d "$folder" ]; then
        # Clear code.cpp
        code_file="$folder/code.cpp"
        if [ -f "$code_file" ]; then
            > "$code_file"
            echo "Cleared contents of $code_file"
        fi
        
        # Clear approach.txt
        approach_file="$folder/approach.txt"
        if [ -f "$approach_file" ]; then
            > "$approach_file"
            echo "Cleared contents of $approach_file"
        fi
    fi
done