#!/bin/bash

main() {
	local SUM_LINES=0
	local COUNT=0

	for FILE in *.txt; do
		aux=$(cat $FILE | wc -l)
		((++COUNT))
		SUM_LINES=$((SUM_LINES + aux))

	done

	echo $(echo "scale=2; $SUM_LINES / $COUNT" | bc)

}

main
