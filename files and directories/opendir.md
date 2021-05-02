# opendir
```cpp
#include <dirent.h>

DIR* opendir(char const* pathname);

DIR* fopendir(int fd);

//return: pointer if OK,NULL on error

struct dirent* readdir(DIR* dp);

//return: pointer if OK,NULL at end of directory or error

void rewinddir(DIR* dp);

int closedir(DIR* dp);

//return:0 if OK,-1 on error

long telldir(DIR* dp);

//return:current location in directory associated with dp

void seekdir(DIR* dp,long loc);
```

> DIR和FILE的作用类似：目录流

```cpp
struct dirent
{
    ino_t d_ino;    //i-node number
    char d_name[];  //null-terminated filename
    //...
};
```

> opendir->readdir会返回目录中的第一个DBE

> fopendir->readdir返回DBE依赖于fd在目录中的偏移位置

> (f)opendir->rewinddir/telldir/seekdir/readdir->closedir

