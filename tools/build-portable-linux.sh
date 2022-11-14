#!/bin/bash

#
# Copyright (C) 2022 https://github.com/nkh-lab
#
# This is free software. You can redistribute it and/or
# modify it under the terms of the GNU General Public License
# version 3 as published by the Free Software Foundation.
#
# This software is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY.
#

# Usage:
# Script input arguments: 
#   '-z' - to archive the package
#

ZIP=0

while getopts z: flag
do
    case "${flag}" in
        u) ZIP=1;;
    esac
done

DIR=$(cd "$(dirname "$0")" && pwd)

PROJECT_ROOT=$(cd $DIR/.. && pwd)
PORTABLE_DIR_REL_PATH="build/portable"
PORTABLE_ARCHIVE_NAME="projectmy-portable"

rm -rf build/
mkdir build && cd build

cmake -Dprojectmy_BUILD_PORTABLE=ON ..
make

cd $PROJECT_ROOT

mkdir $PORTABLE_DIR_REL_PATH
cp build/appmy/appmy $PORTABLE_DIR_REL_PATH
cp build/libmy/libmy.so $PORTABLE_DIR_REL_PATH

cd $PORTABLE_DIR_REL_PATH

if [ $ZIP -eq 1 ]
then
    tar -czf ../$PORTABLE_ARCHIVE_NAME.tar.gz *
fi