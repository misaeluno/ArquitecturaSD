#!/bin/bash

if [[ -n "$1" ]]; then
	if [[ "$1" == *.ino ]]; then
		arduino --upload $1 --port /dev/ttyUSB0
	else
		echo "Must select a .ino file!"
	fi
else
	echo "Must select a .ino file!"
fi
