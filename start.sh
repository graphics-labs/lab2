#!/bin/bash

if test -z "$1"
then
	echo "Undefined file name"
else
	gcc lab2/lab2/$1.cpp -lglut -lGL -lGLU -o $1.out
	./$1.out
fi
