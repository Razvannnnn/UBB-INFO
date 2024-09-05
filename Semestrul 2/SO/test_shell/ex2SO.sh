#!/bin/bash

if [ $# -ne 1 ]
then
	echo "Argumente insuficiente"
	exit 1
fi

cnt=0

find "$1" -type f -name "*.c" | while read -r file
do
	linii=$(wc -l < "$file")
	if [ "$linii" -gt 500 ]
	then
		echo "$file"
		cnt=$((cnt+1))
	fi

	if [ "$cnt" -eq 2 ]
	then
		echo "S-au gasit 2 fisiere .c"
		exit 0
	fi
done
