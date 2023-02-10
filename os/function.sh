#!/bin/sh
function hello(){
echo "Total arguments are $*"
while(( $# ))
do
echo "you said $1"
shift 
done
}
function hello2(){
echo "First argument is $1"
shift 2
echo "After shifting two the first argument is $1"
}
hello world program welcome to programming
hello2 arg1 arg2 arg3 arg4 

