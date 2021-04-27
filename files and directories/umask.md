# umask
```cpp
#include <sys/stat.h>

mode_t umask(mode_t cmask);

//return:previous file mode creation mask
```
> cmask=creation mask，用于创建新文件或新目录的mask
> umask则是将cmask对应的位“turn off”

example:
```cpp
auto fd=creat(pathname,mode);

umask(mode2);

auto fd2=creat(pathname,mode);
//其中mode中mode2的位都被turn off
```