# futimens
```cpp
#include <sys/stat.h>

int futimens(int fd,const struct timespec times[2]);

int utimesnsat(int fd,char const* pathname,const struct timespec times[2],int flag);

//return: 0 if OK,-1 on error
```

这个函数是用来指定时间邮戳的（纳秒粒度，所以后缀为ns）

```cpp
struct timespec
{
    time_t  tv_sec;     //seconds
    long    tv_nsec;    //nanoseconds
};
```

times的两个元素分别对应`st_atime`和`st_mtime`，
有四种方式指定时间邮戳：
* times为null pointer，设定为当前时间
* tv_nsec指定为`UTIME_NOW`，设定为当前时间，tv_sec被忽视
* tv_nsec指定为`UTIME_OMIT`，时间不变，tv_sec被忽视
* tv_nsec指定为其他，设定为该值，tv_sec被忽视

