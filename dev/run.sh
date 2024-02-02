#!/bin/bash
# (run from project root: ./dev/run.sh)

set -e # exit on first error

if [ "$1" = "debug" ]
then
	BUILD_TYPE="debug"
elif [ "$1" = "release" ]
then
	BUILD_TYPE="release"
else
	BUILD_TYPE="debug"
fi

if [ "$BUILD_TYPE" = "debug" ]
then
	echo "== Running Debug =="
	./build/Debug/bin/kiwi
elif [ "$BUILD_TYPE" = "release" ]
then
	echo "== Running Release =="
	./build/Release/bin/kiwi
fi
