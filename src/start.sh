#!/bin/bash
gcc $1.cpp -lglut -lGL -lGLU -o $1.out
./$1.out
