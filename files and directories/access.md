# access
```cpp
#include <unistd.h>

int access(char const* restrict pathname,int mode);

int faccessat(int fd,char const* restrict pathname,int mode,int flag)

//return: 0 if OK,-1 on error
```
> access 和 faccessat都是基于read ID，而open是基于effective ID

|mode|description|
|----|-----------|
|R_OK|test for read permission|
|W_OK|test for write permission|
|X_OK|test for execute permission|

`faccessat`参数：
* fd为AT_FDCWD且pathname为相对路径或pathname为绝对路径（即使AT_FDCWD被指定）时，行为同access。否则评估pathname为打开目录（fd指向的）的相对目录
* flag为AT_EACCESS(effective access)时，访问检验将使用effective ID，而不是real ID

