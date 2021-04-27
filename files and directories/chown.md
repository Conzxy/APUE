# chown
```cpp
#include <unistd.h>

int chown(char const* pathname,uid_t owner,gid_t group);

int fchown(int fd,uid_t owner,gid_t group);

int fchownat(int fd,uid_t owner,gid_t group,int flag);

int lchown(char const* pathname,uid_t owner,gid_t group);

//return:0 if OK,-1 on error
```
