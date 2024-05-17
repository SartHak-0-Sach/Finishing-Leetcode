#!/bin/bash

# Define the path to the parent folder
parent_folder="/c/Users/saksh/OneDrive/Desktop/github/0/Finishing-Leetcode"

# Find all files within sub-folders and clear their contents
find "$parent_folder" -type f -exec sh -c 'echo -n > "$1"' _ {} \;