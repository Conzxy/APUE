# chdir
```cpp
#include <unistd.h>

int chdir(char const* pathname);

int fchdir(int fd);

//return:0 if OK,-1 on error
```

> current working directory（以后简称cwd）是进程的属性，因此不会影响调用执行chdir的进程的进程（比较绕：cannot affect processes that invoke the process that executes the chdir)

