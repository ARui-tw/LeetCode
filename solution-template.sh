#!/bin/bash

# Base directory for all problem folders
base_directory="problems"

# Function to convert the given title into the desired directory format
create_directory_and_file() {
    # Original title passed as argument
    title="$1"

    # Extract problem number and title parts
    problem_number=$(echo "$title" | cut -d '.' -f 1 | xargs)
    problem_title=$(echo "$title" | cut -d '.' -f 2- | xargs)

    # Pad problem number to four digits
    padded_number=$(printf "%04d" "$problem_number")

    # Format the title for directory and URL
    formatted_title=$(echo "$problem_title" | sed 's/ /_/g')
    directory_name="${base_directory}/${padded_number}-${formatted_title}"
    url_title=$(echo "$problem_title" | sed 's/ /-/g' | tr '[:upper:]' '[:lower:]')

    # Construct the LeetCode URL
    problem_url="https://leetcode.com/problems/${url_title}"

    # Create the base directory if it doesn't exist
    mkdir -p "$directory_name"
    file_path="$directory_name/sol.cpp"
    
    # Write header comments to sol.cpp
    cat > "$file_path" <<EOL
/**
 * Author: ARui<mail@arui.dev>
 * Problem: $problem_url
 * Runtime: ms (%)
 */

EOL

    echo "Created $file_path with initial template."

    # Open sol.cpp in vim
    vim "$file_path"
}

# Check if a title is provided as an argument
if [ -z "$1" ]; then
    echo "Please provide a problem title, e.g., '2. Add Two Numbers'"
else
    create_directory_and_file "$1"
fi

