#!/bin/bash

#Write a shell script that takes groups of 3 parameters (a name of a file, a word and a number k).
#For each group, print all the lines from the file that contain the word exactly k times.

#Check if the number of parameters are divisible by 3, to see if we can make groups
#Raises an error otherwise
if [ `expr $# % 3` -ne 0 ]; then
	echo Invalid number of parameters
	exit 0
fi

#If numbers of parameters are equal to 0, raise an error
if [ $# -eq 0 ]; then
	echo Please insert parameters
	exit 1
fi

#Variable that counts the groups
group=0

#While number of parameters are not equal to zero
while [ $# -ne 0 ]; do
	
	#Count the group
	group=`expr $group + 1`
	echo For group $group :

	#Checking the parameters
	#If the first one is not a file, raise an error 
	if [ ! -f $1 ]; then
		echo First parameter not a file
		shift 3
		continue
	fi

	#Variable that contains the length of the name of the file
	len=$(echo "$1" | wc -c)

	#If the length is greater that 255, it is not a filename, raises an error
	if [ $len -gt 255 ]; then
		echo Filename too long >&2
		shift 3
		continue
	fi

	#Raises an error if the first parameter contains "/"
	#Filenames can not contain "/"
	if echo $1 | grep -q "/"; then
		echo Cannot contain /
		shift 3
		continue
	fi

	#Raises an error if the first parameter contains "\0"
	#Filenames can not contain "\0"
	if echo $1 | grep -q "\\0"; then
		echo Cannot contain \\0
		shift 3
		continue
	fi

	#If the word contains spaces, we raise an error
	echo $2 | grep -q " "

	if [ $? -eq 0 ]; then
		echo "Invalid word" >&2
		shift 3
		continue
	fi

	#Raises an error if the third parameter is not a number
	echo $3 | grep -q "^[0-9]*$"

	if [ $? -eq 1 ]; then
		echo Invalid number >&2
		shift 3
		continue
	fi
	
	#Saving the parameters with more descriptive names
	file=$1
	word=$2
	k=$3	

	#while we read each line of the first parameter(the file)
	cat $file | while read line
	do
		#Variable aux contains the number of times the word was found on the current line
		aux=$(echo $line | grep -o "\<$2\>" | wc -w)

		#If aux is indeed equal to k(our third parameter), we print the line
		if [ $aux -eq $k ]; then
			echo $line
		fi 
	done
	
	#shift the parameters by 3
	shift 3
done

