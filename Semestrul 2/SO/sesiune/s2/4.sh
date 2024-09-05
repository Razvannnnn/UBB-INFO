#/bin/bash

handle_directory() {
	DIR_NAME=$1
	cd $DIR_NAME
	local ok=0
	pwd
	for FILE in *; do
		# Daca are extensia .mp3
		if [[ $FILE =~ \.mp3$ && -f $FILE ]]; then
			((++ok))
		fi
		echo "$FILE"
		# Daca este director mergem mai departe
		if [[ -d $FILE ]]; then
			handle_directory "${FILE}"
		fi
	done
	cd ..
	if [[ $ok -gt 0 ]]; then
		echo "1"
	else
		echo "0"
	fi
}

main() {
	# Parcurgem toate fisierele , daca este director mergem mai departe
	for FILE in *; do
		if [[ -d ${FILE} ]]; then
			ans=$(handle_directory "$FILE")
			if [[ $ans == "1" ]]; then
				echo "$FILE has .mp3 in it"
			fi
			echo "$FILE"
		fi
	done
}

main ""
