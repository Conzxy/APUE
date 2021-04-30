# truncate
```cpp
#include <unistd.h>

int truncate(char const* pathname,off_t length);

int ftruncate(int fd,off_t length);

//return:0 if OK,-1 on error
```

> 如果原大小>length，则超出的部分将删除
> 如果原大小<length，则在原文件尾和新文件尾之间形成hole，read将会读为0