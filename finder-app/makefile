# Makefile for writer.c 
# This automates the process of crosscompiling for the compiler type needed
# in assignment 2
# Author: 	A. Saad Imran
# Created: 	November 5, 2023

# if the CROSS_COMPILE argument is set to aarch64-none-linux-gnu- ...
ifeq ($(CROSS_COMPILE), aarch64-none-linux-gnu-)
# we'll use the ARM toolchain for compilation
CC=aarch64-none-linux-gnu-gcc
else
# otherwise, use regular gcc
CC=gcc
endif

# default target, compiles writer.c into writer binary
all:
	${CC} writer.c -o writer   

# clean target removes binary and any object files which may be present
clean:
	rm -f *.o writer
