#!/bin/bash

if [ ! $# -eq 1 ]
then
	echo "Numar argumente invalid"
	exit 1
fi

if [ ! -d "$1" ]
then
	echo "Nu este director"
	exit 1
fi

find "$1" -type f -perm -a=w | while read -r file
do
	echo "Inainte $(ls -l $file | awk '{print $1}') $file"
	chmod a-w "$file"
	echo "Dupa $(ls -l $file | awk '{print $1}') $file"
done
