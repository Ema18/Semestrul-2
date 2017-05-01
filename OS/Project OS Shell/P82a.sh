#!/bin/bash

#Write a shell script that continuously reads words from the keyboard and deletes them from all the files given in the command line.

#Raises an error if we do not have parameters
if [ $# -lt 1 ]; then
	echo Not enough parameters >&2
	exit 1
fi

#Prints onto the screen which parameters are not valid files
for file in $*;
do
	if [ ! -f $file ]; then
		echo $file is not a valid file
	fi
done

#Infinite while 
while [ 1 -eq 1 ];
do
	#Variable word will contain our word
	read word
	
	if [ -z "$word" ]; then
		echo The word should not be empty! >&2
		continue
	fi

	#If the word contains spaces, we raise an error
	echo "$word" | grep -q " "

	if [ $? -eq 0 ]; then
		echo "Invalid word" >&2
		continue
	fi

	#For each parameter in the command line
	for file in $*;
	do
		#if the current parameter is a file, with the sed command I replace the word with nothing. With "-i" the file is modified.
		if [ -f $file ]; then
			sed -i "s/\<$word\>//g" $file
		fi
	done	
done
