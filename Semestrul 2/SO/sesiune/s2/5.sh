#!/bin/bash

# Vector pentru a adauga liniile pentru fisiere cu extensia .sh
declare -a ans

handle_directory() {
	local DIR_NAME=$1

	cd "$DIR_NAME" || return 1

	for FILE in *; do
		if [[ -f $FILE && $FILE =~ \.sh$ ]]; then
			nr_lines=$(wc -l <"$FILE")
			ans+=("$nr_lines")
		elif [[ -d $FILE ]]; then
			handle_directory "$FILE"
		fi
	done

	cd ..
}

main() {
	for FILE in *; do
		if [[ -d $FILE ]]; then
			handle_directory "$FILE"
		fi

		if [[ -f $FILE && $FILE =~ \.sh$ ]]; then
			nr_lines=$(wc -l <"$FILE")
			ans+=("$nr_lines")
		fi
	done

	for a in "${ans[@]}"; do
		echo "$a"
	done

	local sum=0
	local count=0

	for a in "${ans[@]}"; do
		((++count))
		sum=$((sum + a))
	done

	echo "$sum"

	average=$(echo "scale=2; $sum / $count" | bc)
	echo "$average"
}

main
