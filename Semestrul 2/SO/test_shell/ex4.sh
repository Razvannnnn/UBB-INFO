#!/bin/bash

if [ $# -eq 0 ]
then
	echo "Insuficiente argumente"
	exit 1
fi

for i in $*
do
	if [ -d $i ]
	then
		for fis in "$i"/*
		do
			if [ -f $fis ]
			then
				if grep '[0-9]{6,}' "$fis"
				then
					echo "$fis"
				fi
			fi
		done
	else
		echo "Nu este director" $i
	fi
done
