.PHONY: all, clean, rebuild, test

CC = gcc
CFLAGS = -Wall -Werror -Wextra
GLFLAGS = -lglut -lGL -lGLU

PATH = ../build/
SOURCES =  lab2.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = MAIN

all: $(OBJECTS) 
	$(CC) $(GLFLAGS) $(OBJECTS) -o $(PATH)$(EXECUTABLE)

rebuild: claen all

.o: .c
	$(CC) $(GLFLAGS) $< -o $@

clean:
	-rm  $(PATH)*.o
