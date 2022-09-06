#!/bin/bash

if test -z "$1"
then
	echo "Undefined file name"
else
	gcc $1.cpp -lglut -lGL -lGLU -o $1.o
	./$1.o
fi
