#!/bin/sh
a=0

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
