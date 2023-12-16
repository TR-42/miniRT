#!/bin/sh

cd $(dirname $0)

INVALID_RT_FILES=`find ./rt_files -name "invalid.*.rt" -type f -print`
SEPARATOR_STR='-------------------'

echo "Invalid RT files:" $INVALID_RT_FILES

echo $SEPARATOR_STR
for file in $INVALID_RT_FILES
do
	echo "Testing $file"
	./miniRT -c $file
	echo "(Exit Status: $?)"
	echo $SEPARATOR_STR
done
