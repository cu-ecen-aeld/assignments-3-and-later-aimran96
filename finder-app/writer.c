#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <syslog.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main( int argc, char *argv[] )  {
   openlog("writer app", LOG_PID, LOG_USER);
   if( argc == 3 ) {
   	printf("The argument supplied is 1) %s 2) %s\n", argv[1], argv[2]);
   	int outputFd;
	outputFd = open(argv[1], O_WRONLY | O_CREAT , 0666);
	if(outputFd == -1) {
	    /* Error handling */
	    // check errno here
	    syslog(LOG_ERR, "Couldn't open file! %s\n", strerror(errno));
	    printf("Couldn't open file! %s\n", strerror(errno));
	    closelog();
	    return 1;
	}
	ssize_t nr;
	/* write the string in 'argv[2]' to 'outputFd' */
	nr = write (outputFd, argv[2], strlen (argv[2]));
	syslog(LOG_DEBUG, "Writing %s to %s\n", argv[2], argv[1]);
	printf("Writing %s to %s\n", argv[2], argv[1]);
	if (nr == -1){
		// check errno here
		syslog(LOG_ERR, "Couldn't write to file! %s\n", strerror(errno));
		closelog();
		return 1;
	}
	closelog();
	return 0;
	
   }
   else if( argc > 3 ) {
      printf("Too many arguments supplied.\n");
      printf("Two arguments expected.\n");
      syslog(LOG_ERR, "Too many arguments supplied.\nTwo arguments expected.\n");
      closelog();
      return 1;
   }
   else {
      printf("Two arguments expected.\n");
      syslog(LOG_ERR, "Two arguments expected.\n");
      closelog();
      return 1;
   }
}
