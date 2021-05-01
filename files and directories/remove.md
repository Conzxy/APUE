# remove
```cpp
#include <stdio.h>

int remove(char const* pathname);

//return: 0 if OK,-1 on error
```

> 注意头文件，remove是ISO C的一部分

> pathname为目录时，同rmdir，其余同unlink