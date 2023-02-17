#!/bin/usr/env bash
a=0

learn="Start learning from Javatpoint."

while [ $a -lt 10 ]
do
   echo $a
   a=`expr $a + 1`
done

for var in 1 2 3 4 5 6
do 
echo $var
done 
echo -e "hi this is from terminal\nhow are you?"

i=10
while [ $i -ge 0 ]
do
echo "reverse printing $i:"
i=`expr $i - 1`
done

for((ctr=0;ctr<11;ctr++))
do
echo $ctr
done 

for var in "this is from for loop"
do
echo $var
done

for num in {1..5}
do
echo $num
done

for num in {1..10..2}
do
echo $num
done

for num in {10..1..-2}
do
echo $num
done
