#!/bin/bash

if [ $# -eq 0 ]
then
	echo "Insuficiente argumente"
	exit 1
fi

n=$1

for i in $(seq $1)
do
	numefisier="file_$i.txt"
	head -n $((i+5)) passwd.fake | tail -n 5 > "$numefisier"
	echo "A fost creat" $numefisier
done
