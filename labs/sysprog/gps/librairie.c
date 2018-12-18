#include <string.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define KNOT_TO_KMH 1.852

int iteration = 0;

//-----------------------------------------------------------------------------
int hello()
{
    printf("Hello word");
    return 0;
}

//-----------------------------------------------------------------------------
int current_date_str(char * str)
{
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    sprintf(str, "%02d%02d%02d", timeinfo->tm_hour, timeinfo->tm_min,
            timeinfo->tm_sec);
}


