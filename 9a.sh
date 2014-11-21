#!/bin/sh
echo "# to unbundle this file.sh"
for i
do
 echo "echo $1"
 echo "cat >$1<<"end of $1 " "
 cat $1
 echo "end of $1"
done 
