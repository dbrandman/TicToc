#include "Tictoc.h"
#include <unistd.h>
#include <stdio.h>


// Copied from: https://www.gnu.org/software/libc/manual/html_node/Elapsed-Time.html
static void timespec_subtract (struct timespec *result, struct timespec *x, struct timespec *y)
{
    /* Perform the carry for the later subtraction by updating y. */
    if (x->tv_nsec < y->tv_nsec)
    {
        int nsec = (y->tv_nsec - x->tv_nsec) / 1000000000L + 1;
        y->tv_nsec -= 1000000000L * nsec;
        y->tv_sec += nsec;
    }
    if (x->tv_nsec - y->tv_nsec > 1000000000L)
    {
        int nsec = (x->tv_nsec - y->tv_nsec) / 1000000000L;
        y->tv_nsec += 1000000000L * nsec;
        y->tv_sec -= nsec;
    }

    /* Compute the time remaining to wait.
     tv_nsec is certainly positive. */
    result->tv_sec  = x->tv_sec - y->tv_sec;
    result->tv_nsec = x->tv_nsec - y->tv_nsec;
}

int Tic(struct timespec *time1)
{
    return clock_gettime(CLOCK_MONOTONIC, time1);
}

int Toc(struct timespec *time1, struct timespec *timeDifference)
{
    struct timespec time2;
    int val = clock_gettime(CLOCK_MONOTONIC, &time2);
    timespec_subtract(timeDifference, &time2, time1);
    return val;
}

void PrintToc(struct timespec *t)
{
    printf("Elapsed time: %ld seconds, %ld microseconds\n", t->tv_sec, (long) t->tv_nsec);
}

void PrintElapsedTime(struct timespec *tStart)
{
    struct timespec tDifference;
    Toc(tStart, &tDifference);
    PrintToc(&tDifference);
}
