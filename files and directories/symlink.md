# symlink
```cpp
#include <unistd.h>

int symlink(char const* actualpath,char const* sympath);

int symlink(char const* actualpath,int fd,char const* sympath);

//return: 0 if OK,-1 on error
```
