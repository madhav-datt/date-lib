#
# Makefile for test_date program
# Typing 'make' or 'make testdate' will create the executable file.
#
# Madhav Datt - 14CS30015
# Software Engineering Lab - Assignment 3
#

# compiler to use
#
CC = g++

# flags to pass compiler
#
CFLAGS  = -ggdb3 -O0 -std=c++11

# target executable name
#
default: testdate

# for executable file testdate
# object files are date.o, date_comp.o:
#
testdate:  date.o date_comp.o
	$(CC) $(CFLAGS) -o testdate date.o date_comp.o

# for object file date.o
# source files date.cxx, dateformat.cxx, date.h:
#
date.o:  date.cxx dateformat.cxx date.h
	$(CC) $(CFLAGS) -c date.cxx dateformat.cxx

# for object file date_comp.o
# source files date_comp.cxx, date_comp.h:
#
date_comp.o:  date_comp.cxx date_comp.h
	$(CC) $(CFLAGS) -c date_comp.cxx

# remove old *.o object files and *~ backup files:
#
clean:
	$(RM) testdate *.o *~
