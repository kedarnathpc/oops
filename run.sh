#!/bin/bash

# Check if a filename is provided
if [ $# -eq 0 ]; then
    echo "Usage: $0 <cpp_file>"
    exit 1
fi

# Extract filename without extension
filename=$(basename -- "$1")
filename_no_ext="${filename%.*}"

# Compile the C++ file
g++ -o "$filename_no_ext" "$1"

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Running the program..."
    # Run the executable
    ./"$filename_no_ext"
    
    # Delete the executable
    rm "$filename_no_ext"
else
    echo "Compilation failed."
fi
