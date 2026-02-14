#!/bin/bash
set -e

# Directory containing compile_commands.json
BUILD_DIR="build"

# System include path for GCC
GCC_INCLUDE_PATH="/usr/lib/gcc/x86_64-linux-gnu/11/include"

# Verify the include path exists
if [ ! -d "$GCC_INCLUDE_PATH" ]; then
    echo "Error: GCC include path $GCC_INCLUDE_PATH does not exist."
    exit 1
fi

# Run iwyu_tool.py with the system include path
echo "Running Include What You Use with additional system headers..."
python3 tools/scripts/iwyu_tool.py -p "$BUILD_DIR" -- -isystem "$GCC_INCLUDE_PATH"

echo "iwyu completed successfully."
