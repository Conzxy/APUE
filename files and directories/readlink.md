# readlink
```cpp
#include <unistd.h>

ssize_t readlink(char const* restrict pathname,char* restrict buf,size_t bufsize);

ssize_t readlinkat(int fd,char const* restrict pathname,char* restrict buf,size_t bufsize);

//return: number of bytes read if OK,-1 on error
```
