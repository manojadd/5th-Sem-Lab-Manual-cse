#!/bin/sh
#program to check permission
if [ $# -ne 2 ]
then
echo "Execution is sh 8a.sh first_file second file"
exit 2
fi
#permission of first file
p1=`ls -l $1|cut -d " " -f1`
#permission of second file
p2=`ls -l $2 |cut -d " " -f1`
if test $p1 = $p2
then
echo "the permission are same"
echo $p1
else
echo "the permission are different"
echo "filename :$1 operation :$p1"
echo "filename :$2 operation :$p2"
fi
exit 0
