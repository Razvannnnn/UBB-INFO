#!/bin/bash

if [ $# -eq 0 ]
then
	echo "Insuficiente argumente"
	exit 1
fi

if [ ! -d "$1" ]
then
	echo "Argumentul nu este director"
	exit 1
fi

file "$1" -type f -perm -222 | while read -r file
do
	for i in "$file"
	do
		mv "$file" "$file.all"
	done
done
