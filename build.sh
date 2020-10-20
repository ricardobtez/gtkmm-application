#!/bin/bash

BUILD_DIR=./build

# Get all the passed arguments
args=("$@")
NUMBER_OR_PARAMETERS=${#args[@]}

if [ 1 -eq ${NUMBER_OR_PARAMETERS} ]
then
    if [ ${args[0]} = 'debug' ]
    then
        RELEASE_TYPE=Debug
    else
        RELEASE_TYPE=Release
    fi
else
    RELEASE_TYPE=Release
fi
#RELEASE_TYPE=$1

# Check if the build directory already exists
if [ ! -d $BUILD_DIR ]
then
    mkdir $BUILD_DIR
    cd $BUILD_DIR
    cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=${RELEASE_TYPE} ..
    cd ..
else
    echo "The build directory already exists"
fi
echo ----------------------------------------
echo Automated Build script
echo Release type selected: ${RELEASE_TYPE}
echo ----------------------------------------

cd $BUILD_DIR

make -j4 2>error_output.txt
python ../warnings.py

cd ..
