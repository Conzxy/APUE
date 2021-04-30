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
* fd为AT_FDCWD时，
  * pathname为相对路径，则为当前目录的相对路径
  * pathname为绝对路径，忽略fd，行为同access
* fd指定其他，pathname为打开目录（fd指向的）的相对路径
* flag为AT_EACCESS(effective access)时，访问检验将使用effective ID，而不是real ID

