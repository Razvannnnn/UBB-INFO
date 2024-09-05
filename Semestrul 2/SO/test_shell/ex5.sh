#!/bin/bash

if [ $# -eq 0 ]
then
	echo "Insuficiente argumente"
	exit 1
fi

sum=0
cnt=0


if [ ! -d $1 ]
then
	echo "Nu este director"
	exit 1
fi

find "$1" -type f | while read -r file
do
	if file "$file" | grep 'text'
	then
		nr_lin=$(wc -l < "$file")
		sum=$((sum+nr_lin))
		cnt=$((cnt+1))
	fi
done

if [ $cnt -gt 0 ]
then
	avg=$((sum/cnt))
	echo "Numar fisier average" $avg
else
	echo "Nu exista fisiere text"
fi


