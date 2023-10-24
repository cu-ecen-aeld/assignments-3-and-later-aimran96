#!/bin/sh

if [ -z $1 ] || [ -z $2 ]
then
	echo "Not enough arguments, program expects the following arguments:"
	echo "1) writefile: directory and filename to write to"
	echo "2) writestr: string to write"
	exit 1
else 
	filename=$1
	data=$2
	DIR="$(dirname "${filename}")" 
	mkdir -p $DIR
	touch ${filename}
	echo "${data}" > ${filename}
fi
