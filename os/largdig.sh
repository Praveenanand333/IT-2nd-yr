#!/bin/sh
echo "Enter the number"
read a
temp=a
high=0
while [[ $temp -gt 0 ]]
do
rem=$((temp%10))
temp=$((temp/10))
if [ $rem -gt $high ]
then
high=$rem
fi
done
echo "The greatest digit is $high"

