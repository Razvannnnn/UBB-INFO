#!/bin/bash

awk '{print $1}' "who.fake" | while read -r name
do
	echo -n "$name "
	grep "^$name" "ps.fake" | wc -l
done
