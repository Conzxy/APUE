# chmod
```cpp
#include <sys/stat.h>

int chmod(char const* pathname,mode_t mode);

int fchmod(int fd,mode_t mode);

int fchmodat(int fd,char const* pathname,mode_t mode,int flag)
//return:0 if OK,-1 on error
```

| mode | Description|
|--|--|
|S_ISUID|set-user-ID on execution|
|S_ISGID|set-user-ID on execution|
|S_ISVTX|saved-text(sticky bit)|
|S_IRWXU|read,write,execute by user|
|S_IRUSR|read by user|
|S_IWUSR|write by user|
|S_IXUSR|execute by user|
|S_IRWXG|read,write,execute by group|
|S_IRGRP|read by group|
|S_IWGRP|write by group|
|S_IXGRP|execute by group|
|S_IRWXO|read,write,execute by other|
|S_IROTH|read by other|
|S_IWOTH|write by other|
|S_IXOTH|execute by other|


