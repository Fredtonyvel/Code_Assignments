#!/bin/bash

echo 'Welcome to the Account Inheritance Hierarchy!'
echo 'Choose from the follwing:'
echo '1. Administrator'
echo '2. User'
echo '3. Exit'

read choice
if [ $choice == 1 ]; then
	./Admin_script.sh
elif [ $choice == 2 ]; then
	./User_script.sh
elif [ $choice == 3 ]; then
	echo 'Have a wonderful day!'
fi

