#!/bin/bash

set -e # exit on first error

if [ "$1" = "debug" ]
then
	BUILD_TYPE="Debug"
elif [ "$1" = "release" ]
then
	BUILD_TYPE="Release"
else
	echo "== Select type of build: =="
	PS3="Please enter your choice: "
	OPTIONS=("Debug" "Release" "Quit")
	select OPT in "${OPTIONS[@]}"
	do
		case $OPT in
			"Debug")
				BUILD_TYPE="Debug"
				break
				;;
			"Release")
				BUILD_TYPE="Release"
				break
				;;
			"Quit")
				exit 0
				;;
			*) echo "Invalid option $REPLY";;
		esac
	done
fi

echo "== Building $BUILD_TYPE =="
EXP_CC=false
if [ "$2" = "-c" ]
then
	# export compile commands for clangd autocompletion
	EXP_CC=true
	EXTRA_FLAGS="-DCMAKE_EXPORT_COMPILE_COMMANDS=1"
fi
cmake -S . -B build/$BUILD_TYPE -DCMAKE_BUILD_TYPE=$BUILD_TYPE $EXTRA_FLAGS
cd build/$BUILD_TYPE
if [ "$EXP_CC" = true ]
then
	mv -f compile_commands.json ..
fi
make -j$(nproc)
