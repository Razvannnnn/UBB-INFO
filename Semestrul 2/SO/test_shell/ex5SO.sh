#!/bin/bash

if [ $# -eq 0 ]
then
	echo "Numar argumente insuficient"
	exit 1
fi

for name in $*
do
	mv "ps.fake.tmp" "ps.fake"
	grep '$name' "ps.fake.tmp"
	cnt=$(wc -l < "ps.fake.tmp")
	if [ "$cnt" -gt 0 ]
	then
		echo "Killing $name"
		kill $(awk '{print $2}' "ps.fake.tmp")
	fi
done
