#!/bin/bash

if [ ! $# -eq 1 ]
then
	echo "Argumente insuficiete"
	exit 1
fi

find "$1" -type f -name "*.log" | while read -r file
do
	sort -o "$file" "$file"
	echo "Sortat $file"
done
