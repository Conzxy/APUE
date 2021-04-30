# creat

```cpp
#include <fcntl.h>

int creat(const char* path,mode_t mode);

//return:fd opened for write-only if OK,-1 on error
```

> 等价于open(path,O_WRONLY|O_CREAT|O_TRUNC,mode)
> 注意不是create而是`creat`！

# close

```cpp
#include <unistd.h>

int close(int fd);
//return:0 if OK,-1 on error
```

> 注意：当进程终止时，所有打开的文件都会自动关闭