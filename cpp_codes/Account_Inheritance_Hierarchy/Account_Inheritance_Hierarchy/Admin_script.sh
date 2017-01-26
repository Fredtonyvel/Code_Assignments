#!/bin/bash

g++ -std=c++0x Account.cpp SavingsAccount.cpp admin_main.cpp -o execute

if [ $? == 0 ]; then
	./execute
fi

