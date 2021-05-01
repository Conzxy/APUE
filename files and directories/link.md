# link
```cpp
#include <unistd.h>

int link(char const* existingpath,char const* newpath);

int linkat(int efd,char const* existingpath,int nfd,char const* newpath,int flag);

//return:0 if OK，-1 on error
```
由于硬链接是一种共享机制，如果newpath已存在，那么会触发error，即返回-1。

> 按老规矩，efd指定为AT_FDCWD，existingpath解释为当前目录的相对路径，其他的不再赘述，nfd同上

>flag指定为`AT_SYMLINK_FOLLOW`时，建立对符号链接引用文件的硬链接，即默认建立对符号链接本身的硬链接

> 创建目录的硬链接需要su权限，防止形成环形引用

环形引用栗子：
```
mkdir -p /tmp/a/b
cd /tmp/a/b
ln /tmp/a l
```
将会导致目录循环遍历有无穷的深度，实际上破坏了树结构，形成了环
```
cd /tmp/a/b/l/b/l/b/l
```
还有一个问题，则会导致`..`指代不明
```
cd /tmp/a/b
cd /tmp/a/b/l/b
```
请问这时，b目录中的`..`是指`/tmp/a`还是`/tmp/a/b/l`？

为了解决该问题，诞生了符号链接，由于它本质上是一种文件类型并且不是通过inode指针引用，因此并不会造成硬链接出现的问题

