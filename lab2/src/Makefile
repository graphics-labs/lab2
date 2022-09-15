.PHONY: all, clean, rebuild 

CC = gcc
CFLAGS = -c
GLFLAGS = -lglut -lGL -lGLU

BUILD_PATH = ../build/
SOURCES =  lab2.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = MAIN

all: $(OBJECTS)
	$(CC) $(GLFLAGS) $(BUILD_PATH)$(OBJECTS) -o $(BUILD_PATH)$(EXECUTABLE)

rebuild: clean all

%.o: %.cpp
	$(CC) $(CFLAGS) $(GLFLAGS) $< -o $(BUILD_PATH)$@

clean:
	-rm  $(BUILD_PATH)*
