#!/bin/bash

if [ $# -lt 3 ]
then
	echo "Insuficiente argumente"
	exit 1
fi

while [ $# -ge 3 ]
do
	file="$1"
	cuv="$2"
	nr="$3"

	if [ ! -f "$file" ]
	then
		echo "'$file' nu este fisier"
	else
		awk -v cuv="$cuv" -v nr="$nr" '{if(gsub(cuv, &)==nr print}' "$file"
	fi
	shift 3
done
