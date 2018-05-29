# TicToc
The Matlab TicToc function written in C

Matlab's TicToc function is rather useful. I implemented this in C, based on [previously written code](https://www.gnu.org/software/libc/manual/html_node/Elapsed-Time.html)

```C

#include "Tictoc.h"
#include <stdio.h>
#include <unistd.h>

int main()
{
    struct timespec tStart = Tic();

    usleep(1000);
        
    struct timespec tEnd = Toc(&tStart);
    PrintToc(&tEnd);
        
    return 0;
}
```

I recognize that it's cleaner to pass pointers to memory rather than returning structures from functions. But! I wanted the implementation to be Matlab's syntax.
