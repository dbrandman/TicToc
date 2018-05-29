/**
 * @file
 * @author David Brandman
 * @brief Calculate time elapsed between Tic() and Toc().
 */

#include <time.h>
#include <sys/time.h>

/** Store the current system time. */
int Tic(struct timespec *time1);

/** Return time elapsed since call to Tic(). */
int Toc(struct timespec *time1, struct timespec *time2);

/** Print any `struct timespec` to console. */
void PrintToc(struct timespec *t);

/** Get time elapsed since Tic() and print to console. */
void PrintElapsedTime(struct timespec *t);
