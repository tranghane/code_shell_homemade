#!/bin/sh
#
# DON'T EDIT THIS!
#
# CodeCrafters uses this file to test your code. Don't make any changes here!
#
# DON'T EDIT THIS!
set -e
# vcpkg & cmake are required. 
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=/home/ocean/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build ./build
exec ./build/shell "$@"
