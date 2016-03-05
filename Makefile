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
CFLAGS  = -ggdb3 -std=c++11

# target executable name
#
default: tester

# for executable file testdate
# object files are date.o, date_comp.o:
#
tester:  test_date.o date.o date_comp.o dateformat.o
	$(CC) $(CFLAGS) -o tester test_date.o date.o date_comp.o dateformat.o

# for object file test_date.o
# source files test_date.cxx, date.h:
#
test_date.o:  test_date.cxx date.h
	$(CC) $(CFLAGS) -c test_date.cxx

# for object file date.o
# source files date.cxx, dateformat.cxx, date.h:
#
date.o:  date.cxx date.h date_comp.h
	$(CC) $(CFLAGS) -c date.cxx

# for object file dateformat.o
# source files dateformat.cxx, date.h, date_comp.h:
#
dateformat.o:  dateformat.cxx date.h date_comp.h
	$(CC) $(CFLAGS) -c dateformat.cxx

# for object file date_comp.o
# source files date_comp.cxx, date_comp.h:
#
date_comp.o:  date_comp.cxx date.h date_comp.h
	$(CC) $(CFLAGS) -c date_comp.cxx

# remove old *.o object files and *~ backup files:
#
clean:
	$(RM) testdate *.o *~
