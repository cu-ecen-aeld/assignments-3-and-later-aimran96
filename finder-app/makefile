ifeq ($(CROSS_COMPILE), aarch64-none-linux-gnu-)
CC=aarch64-none-linux-gnu-gcc
else
CC=gcc
endif

all:
	${CC} writer.c -o writer   
     
clean:
	rm -f *.o writer
