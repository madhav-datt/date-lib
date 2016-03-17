#
# Makefile for test_date program
# Typing 'make' or 'make testdate' will create the executable file.
#
# Copyright (C)   2016    Madhav Datt
# http://www.gnu.org/licenses/old-licenses/gpl-2.0.html
#

# compiler to use
#
CC = g++

# flags to pass compiler
#
CFLAGS  = -ggdb3 -std=c++11

# target executable name
#
default: testdate

# for executable file testdate
# object files are date.o, date_util.o:
#
testdate:  test_date.o date.o date_util.o dateformat.o
	$(CC) $(CFLAGS) -o testdate test_date.o date.o date_util.o dateformat.o

# for object file test_date.o
# source files test_date.cxx, date.h:
#
test_date.o:  test_date.cxx date-lib/date.h
	$(CC) $(CFLAGS) -c test_date.cxx

# for object file date.o
# source files date.cxx, dateformat.cxx, date.h:
#
date.o:  date-lib/date.cxx date-lib/date.h date-lib/date-util-lib/date_util.h
	$(CC) $(CFLAGS) -c date-lib/date.cxx

# for object file dateformat.o
# source files dateformat.cxx, date.h, date_util.h:
#
dateformat.o:  date-lib/dateformat.cxx date-lib/date.h date-lib/date-util-lib/date_util.h
	$(CC) $(CFLAGS) -c date-lib/dateformat.cxx

# for object file date_util.o
# source files date_util.cxx, date_util.h:
#
date_util.o:  date-lib/date-util-lib/date_util.cxx date-lib/date.h date-lib/date-util-lib/date_util.h
	$(CC) $(CFLAGS) -c date-lib/date-util-lib/date_util.cxx

# remove old *.o object files and *~ backup files:
#
clean:
	$(RM) testdate *.o *~
