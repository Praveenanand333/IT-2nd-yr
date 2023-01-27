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
