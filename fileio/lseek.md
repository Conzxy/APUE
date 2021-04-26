# lseek

```cpp
#include <unistd.h>

off_t lseek(int fd,off_t offset,int whence);

//return: new file offset if OK,-1 on error
```

whence决定如何解释offset

| whence   | interpretation                                |
| -------- | --------------------------------------------- |
| SEEK_SET | 文件偏移设置为offset                          |
| SEEK_CUR | 文件偏移设置为当前值+offset（可正可负）       |
| SEEK_END | 文件偏移设置为文件大小+offset（**可正可负**） |

