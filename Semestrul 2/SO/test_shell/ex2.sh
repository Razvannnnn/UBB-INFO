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
		echo -n "Fisier " $i
		nr_caract=$(wc -m < "$i")
		nr_linii=$(wc -l < "$i")
		echo " ($nr_caract caractere, $nr_linii linii)"
	elif [ -d $i ]
	then
		echo -n "Director " $i
		nr_fisier=$(find '$i' -type f | wc -l)
		echo "Numar fisiere " $nr_fisier
	else
		echo -n "Argument invalid" $i
	fi
done
