# chown
```cpp
#include <unistd.h>

int chown(char const* pathname,uid_t owner,gid_t group);

int fchown(int fd,uid_t owner,gid_t group);

int fchownat(int fd,uid_t owner,gid_t group,int flag);

int lchown(char const* pathname,uid_t owner,gid_t group);

//return:0 if OK,-1 on error
```
> 指定`AT_SYMLINK_NOFOLLOW`的fchownat和lchown作用于符号链接本身

> fchownat的fd指定为AT_FDCWD，则pathname解释为当前目录的相对路径，如果pathname为绝对路径，忽略fd。fd为其他打开目录时，pathname解释为相对其的相对路径

> 如果owner或group为-1，则对应的ID不变

