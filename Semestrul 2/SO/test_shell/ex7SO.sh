#!/bin/bash

if [ $# -eq 0 ]
then
	echo "Insuficiente argumente"
	exit 1
fi

while [ ! -z "$1" ]
do
	echo -n "$1@scs.ubbcluj.ro"
	if [ ! -z "$2" ]
	then
		echo -n ","
	else
		echo ""
	fi
	shift 1
done
