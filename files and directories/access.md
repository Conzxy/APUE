# access
```cpp
#include <unistd.h>

int access(char const* restrict pathname,int mode);

int faccessat(int fd,char const* restrict pathname,int mode,int flag)

//return: 0 if OK,-1 on error
```
|mode|description|
|----|-----------|
|R_OK|test for read permission|
|W_OK|test for write permission|
|X_OK|test for execute permission|

* fd为AT_FDCWD时....
* flag为AT_EACCESS(effective access)时，访问检验将使用effective ID，而不是real ID