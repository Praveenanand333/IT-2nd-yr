#!/bin/sh
#use bash fiename.sh to run the file
name="anand"
echo "hello $name"
echo $name
echo "First Parameter : $1"
echo "Second Parameter : $2"
echo "Total Number of Parameters : $#"
NAME[0]="Zara"
NAME[1]="Qadir"
NAME[2]="Mahnaz"
NAME[3]="Ayan"
NAME[4]="Daisy"
echo "${NAME[1]}"
#for accessing the entire array
echo "First Method: ${NAME[*]}"
echo "Second Method: ${NAME[@]}"
val[0]=`expr 2 \* 5`
val[1]=`expr 2 + 5`
val[2]=`expr 2 - 5`
val[3]=`expr 2 / 5`
echo "Total value : ${val[*]}"
echo "enter a:"
read a
echo "enter b:"
read b

if [ $a == $b ]
then
   echo "a is equal to b"
else
   echo "a is not equal to b"
fi

if [ $a == $b ]
then
   echo "a is equal to b"
fi

if [ $a != $b ]
then
   echo "a is not equal to b"
fi
if [ $a == $b ]
then
   echo "a is equal to b"
elif [ $a -gt $b ]
then
   echo "a is greater than b"
elif [ $a -lt $b ]
then
   echo "a is less than b"
else
   echo "None of the condition met"
fi

FRUIT="kiwi"

case "$FRUIT" in "apple") echo "Apple pie is quite tasty." ;;
   "banana") echo "I like banana nut bread." ;;
   "kiwi") echo "New Zealand is famous for kiwi." ;;
esac
c=0
let c=$c+1
echo $c
