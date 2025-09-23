#!/bin/bash

if (( $# == 2 )); then
	writefile=$1
	writestr=$2
else
	echo "Number of arguments passed is not 2. Exiting"
	exit 1
fi

mkdir -p "${writefile%/*}" && echo "$writestr" > "$writefile"
if [[ ! -d "${writefile%/*}" ]]; then
	echo "Error in creating the dir ${writefile%/*}"
	exit 1
fi

if [[ ! -f "$writefile" ]]; then
	echo "Error in creating the file $writefile"
	exit 1
fi

if [[ $(cat "$writefile") != "$writestr" ]]; then
	echo "Input string was not written correctly to $writefile"
	exit 1
fi
