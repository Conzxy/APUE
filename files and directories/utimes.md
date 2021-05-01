# utimes
```cpp
#include <sys/time.h>

int utimes(char const* pathname,const struct timeval times[2]);

//return: 0 if OK,-1 on error
```

```cpp
struct timeval
{
    time_t  tv_sec;     //seconds
    long    tv_usec;    //microseconds
};
```

> timeval与timespec的粒度不同，前者是微秒，后者是纳秒