#!/bin/bash

function menu ()
{
	echo 'Welcome to the Account Inheritance Hierarchy!'
	echo 'Choose from the follwing:'
	echo '1. Administrator'
	echo '2. User'
	echo '3. Exit'
	echo 
}

menu
echo "choice: "
read choice

while [ $choice -ne 3 ]; do
	if [ $choice -eq 1 ]; then
		./Admin_script.sh
	elif [ $choice -eq 2 ]; then
		./User_script.sh
	elif [ $choice -eq 3 ]; then
		exit
	fi
	menu
	echo "choice: "
	read choice
done

echo 'Have a wonderful day!'