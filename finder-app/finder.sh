#!/bin/bash


if (( $# == 2 )); then
	filesdir=$1
	searchstr=$2
else
	echo "Number of arguments passed is not 2. Exiting"
	exit 1
fi


if [[ ! -d "$filesdir" ]]; then
	echo "First argument is not a dir. Exiting"
	exit 1
fi
file_names=$(find $filesdir -type f -printf "%f\n")
X=$(echo "$file_names" | wc -l)
Y=$(grep -R "$filesdir" -e "$searchstr" | wc -l)
printf "The number of files are %s and the number of matching lines are %s\n" $X "${Y:=0}"
