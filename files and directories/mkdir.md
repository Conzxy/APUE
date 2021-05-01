# mkdir
```cpp
#include <sys/stat.h>

int mkdir(char const* pathname,mode_t mode);

int mkdirat(int fd,char const* pathname,mode_t mode);

//return: 0 if OK,-1 on error
```
