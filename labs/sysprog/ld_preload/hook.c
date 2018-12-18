// Question 8 : write here the buggy function without errors
#include <stdio.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

#define KNOT_TO_KMH 1.852

int knot_to_kmh_str(float not, size_t size, char * format, char * kmh_str)
{
    float kmh = KNOT_TO_KMH * not;
    snprintf(kmh_str, size, format, kmh);
    return kmh;
}

// Question 12 : write printf with a signal handler
void signal_handler(int signal_number)
{
	printf(stdout, "on ne peut plsu utiliser CTRL-C");
}

int printf(const char *format, ...)
{
    struct sigaction action;
    action.sa_handler = signal_handler;
    sigemptyset(& (action.sa_mask));
    action.sa_flags = 0;
    sigaction(SIGINT, & action, NULL);

//    while(1)
  //  {
//	printf("sleep...\n");
//	sleep(2);
  //  }
    
    //return EXIT_SUCCESS;
}
