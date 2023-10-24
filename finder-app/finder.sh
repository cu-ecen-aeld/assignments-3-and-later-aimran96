#!/bin/sh

if [ -z $1 ] || [ -z $2 ]
then
	echo "Not enough arguments, program expects the following arguments:"
	echo "1) filesdir: directory of files"
	echo "2) searchstr: string to search for"
	exit 1
else 
	if [ -d $1 ]
	then
		filesdir=$1
		searchstr=$2
		number_of_files=$(grep -r -l "${searchstr}" $filesdir | wc -l)
		number_of_lines=$(grep -r "${searchstr}" ${filesdir} | wc -l)
		echo "The number of files are ${number_of_files} and the number of matching lines are ${number_of_lines}"
	else 
		echo "First argument is not a directory"
		echo "Please specify a proper directory as the first argument"
		return 1
	fi
fi

