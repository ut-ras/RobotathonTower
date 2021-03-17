#!/bin/bash
# File: build.sh
# Author: Matthew Yu
# Last Modified: 03/14/21
# Description: A build script for building the Dancebot project and flashing it
# to the device. Use with care, and in the Dancebot repository, since this uses
# relative links.

# Replace your .ino file path with whatever project you want to build and flash!
SKETCH_PATH="./src/HelloWorld.ino"

while [[ "$#" -gt 0 ]]; do
    case $1 in
        -c|--compile)
            echo "Compiling HelloWorld.ino";
            espmake32 SKETCH=$SKETCH_PATH LIBS="./inc/" BUILD_DIR="./build/";
            ;;
        -f|--flash)
            echo "Compiling HelloWorld.ino and flashing to the ESP32 device, if any.";
            espmake32 SKETCH=$SKETCH_PATH LIBS="./inc/" BUILD_DIR="./build/" flash;
            ;;
        -m|--monitor)
            echo "Opening serial monitor for ESP32 device, if any.";
            espmake32 monitor;
            ;;
        -h|--help)
            echo "add flag -c or --compile to compile the project.";
            echo "add flag -f or --flash to compile and flash the project.";
            echo "add flag -m or --monitor to open the serial monitor in the CLI.";
            echo "both flash and monitor commands require the ESP32 to be connected.";
            ;;
        *) echo "Unknown parameter passed: $1"; exit 1 ;;
    esac
    shift
done