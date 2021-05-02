# getcwd
```cpp
#include <unistd.h>

char* getcwd(char* buf,size_t size);

//return:buf if OK，NULL on error
```

> 得到cwd的绝对路径

> 以当前目录(`.`)的inode开始，逐步往上层直到碰到根目录`/`。在每个层次，都会根据对应的inode获取其文件名，最后组合成绝对路径

