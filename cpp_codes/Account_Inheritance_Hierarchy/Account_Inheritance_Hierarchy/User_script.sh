#!/bin/bash

g++ Account.cpp user_main.cpp -o execute

if [ $? == 0 ]; then
	./execute
fi

