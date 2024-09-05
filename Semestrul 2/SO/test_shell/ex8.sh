#!/bin/bash

if [ $# -eq 0 ]
then
	echo "Insuficiente argumente"
	exit 1
fi

for file in $*
do
	if [ ! -f "$file" ]
	then
		echo "'$file' nu este fisier"
	else
		sort "$file" | uniq -c | sort -n -r | head -n 1
	fi
done
