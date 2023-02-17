#!/bin/sh
name="anand"
len=${#name}
echo "$len"
echo "Enter name"
read -a names
echo "The entered names are:${names[*]}"
read -p "Enter the username" username
read -sp "Enter the password" password
echo "username:$username"
echo "Password:$password"



