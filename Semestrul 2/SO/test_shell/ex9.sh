#!/bin/bash

if [ $# -eq 0 ]
then
	echo "Insuficiente argumente"
	exit 1
fi

if [ ! -d "$1" ]
then
	echo "'$1' nu e director"
	exit 1
fi

file "$1" -type f | while read -r file
do
	filename=$(basename "$file")
	if [["$filename"=~ ^.{1,7}$]]
	then
		if file "$file" | grep -q 'text'
		then
			head "$file"
		fi
	fi
done


