#!/bin/bash
echo -n "What is your name?"
read username
echo -e "\n the even numbers are:"
print_three "$0" "$2" "$4"
echo -e "\n the odd numbers are:"
print_three "$1" "$3" "$5"
print_three(){
	echo "The first parm in the function is: $1"
	echo "The second parm in the function is: $2"
	echo "The third parm in the function is: $3"
echo "\n The name entered when the program was started was: $username"
