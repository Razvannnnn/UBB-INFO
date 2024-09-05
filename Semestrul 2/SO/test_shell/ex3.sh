#!/bin/bash

if [ $# -eq 0 ]
then
	echo "Insuficiente argumente"
	exit 1
fi

for i in $*
do
	if [ -f $i ]
	then
		nr_linii=$(wc -l "$i")
		if [ $nr_linii -lt 10 ]
		then
			cat $i
		else
			head -n 5 "$i"
			tail -n 5 "$i"
		fi
	else
		echo "Nu este fisier" $i
	fi
done
