#!/bin/bash

g++ Account.cpp SavingsAccount.cpp CheckingAccount.cpp admin_main.cpp -o execute

if [ $? == 0 ]; then
	./execute
fi

