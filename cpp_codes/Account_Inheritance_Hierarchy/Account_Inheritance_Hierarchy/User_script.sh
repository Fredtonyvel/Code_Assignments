#!/bin/bash

g++ Account.cpp SavingsAccount.cpp CheckingAccount.cpp user_main.cpp -o execute

if [ $? == 0 ]; then
	./execute
fi

