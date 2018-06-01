
#include <stdio.h>
#include <unistd.h>

#include "Tictoc.h"
int main()
{
	struct timespec time1, time2;
	time1 = Tic();
	
	usleep(10000);
	
	time2 = Toc(&time1);
	
	PrintToc(&time2);

	return 0;
}
