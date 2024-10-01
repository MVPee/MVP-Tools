#!/bin/bash

APPLICATION=MVP
BREW_DIR="/Users/${USER}/.brew/bin"
BIN_DIR="/usr/bin"

make &> /dev/null

if [ -f "$APPLICATION" ]; then
    if [[ "$OSTYPE" == "darwin"* ]]; then
        mv "$APPLICATION" "$BREW_DIR" &> /dev/null
        if [ $? -ne 0 ]; then
            echo "Failed to move $APPLICATION to $BREW_DIR. Attempting to move to $BIN_DIR."
            sudo mv "$APPLICATION" "$BIN_DIR" &> /dev/null
            if [ $? -ne 0 ]; then
                echo "Error: Unable to move $APPLICATION to any bin directory. You can try to install brew."
                exit 1
            fi
        fi
        DIR="$BREW_DIR"
    elif [[ "$OSTYPE" == "linux-gnu"* ]]; then
        sudo mv "$APPLICATION" "$BIN_DIR" &> /dev/null
        DIR="$BIN_DIR"
        if [ $? -ne 0 ]; then
            echo "Error: Unable to move $APPLICATION to $BIN_DIR."
            exit 1
        fi
    else
        echo "Error: OS not supported for the script. You can try to manually move the binary to your bin folder (/usr/bin)."
        exit 1
    fi
    
    if [[ ":$PATH:" != *":$DIR:"* ]]; then
        echo "/!\\ $DIR is not in \$PATH. You may need to add it for easier access."
    else
        echo "Successfully installed $APPLICATION in $DIR."
    fi

    echo "Usage: $APPLICATION [-h | cmd]."
else
    echo "Error: Compilation failed."
    exit 1
fi
