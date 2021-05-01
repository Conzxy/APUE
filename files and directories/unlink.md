# unlink
```cpp
#include <unistd.h>

int unlink (char const* pathname);

int unlinkat(int fd,char const* pathname,int flag);

//return: 0 if OK,-1 on error
```
> 需要注意的是unlink并不能作用于目录

> 只有当链接计数为0时，才会删除该文件内容，但是如果有进程打开了该文件，该文件需要等到所有打开了该文件的进程都关闭之后才会删除该文件

> 内核会在文件关闭时，检查有多少个进程打开了该文件，并待进程数为0时检查链接计数

> 当unlinkat的flag指定为`AT_REMOVEDIR`时可以作用于目录（同rmdir），需要注意的是指定后**只能**作用于目录