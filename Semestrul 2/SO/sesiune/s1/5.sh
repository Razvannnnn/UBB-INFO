#!/bin/bash

handle_directory() {
	# Aici facem numarul de fisiere pe care il are acest directo
	DIR_NAME="$1"
	local count=0

	if [[ -d "$DIR_NAME" ]]; then
		cd "$DIR_NAME" || return 0
		for FILE in *; do
			if [[ -f "$FILE" && "$FILE" =~ ".txt" ]]; then
				((++count))
			fi
		done
		echo "$count"
	else
		echo "Directory "$DIR_NAME" not found"
	fi

}

main() {
	for FILE in *; do
		echo $FILE
		if [[ -d "$FILE" ]]; then #director
			ans=$(handle_directory "$FILE")
			echo "$FILE has $ans files"
		fi
	done
}

main ""
