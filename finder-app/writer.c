#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main( int argc, char *argv[] )  {

   if( argc == 3 ) {
   	printf("The argument supplied is 1) %s 2) %s\n", argv[1], argv[2]);
   	int outputFd;
	outputFd = open(argv[1], O_WRONLY | O_CREAT , 0666);
	if(outputFd == -1) {
	    /* Error handling */
	    return 1;
	}
	ssize_t nr;
	/* write the string in 'buf' to 'fd' */
	nr = write (outputFd, argv[2], strlen (argv[2]));
	return 0;
	
   }
   else if( argc > 3 ) {
      printf("Too many arguments supplied.\n");
      printf("Two arguments expected.\n");
      return 1;
   }
   else {
      printf("Two arguments expected.\n");
      return 1;
   }
}
