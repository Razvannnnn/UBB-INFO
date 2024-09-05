#!/bin/bash

if [ ! $# -eq 1 ]
then
	echo "Numar argumente invalid"
	exit 1
fi

if [ ! -d $1 ]
then
	echo "Argumentul nu este director"
	exit 1
fi

find "$1" -type l | while read -r link
do
	if [ ! -e "$link" ]
	then
		echo "$link nu conduce nicaieri"
	fi
done
