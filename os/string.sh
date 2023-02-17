#!/bin/sh
name="anand"
len=${#name}
echo "$len"
read -p "Enter the string separated by space:" str
IFS=''
read -ra ADDR str
for i in ${ADDR[*]}
do
echo "$i"
echo -e "\n"
done





