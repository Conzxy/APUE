# rename
```cpp
#include <stdio.h>

int rename(char const* oldname,char const* newname);

int renameat(int oldfd,char const* oldname,int newfd,char const* newname);

//return:0 if OK,-1 on error
```

rename对于oldname有一定要求：
1.non-dir
* newname不能为目录
* 若newname已存在，将移除该文件，并将oldname改为newname
* 你要确保拥有包含oldname和newname的目录的写权限

2.dir
* 若newname已存在，该目录必须为空（即只有`.`和`..`），将移除该目录，并将oldname改为newname
* newname不能包含oldname的前缀路径

3.如果是符号链接，作用于文件本身

4.不能重命名`.`和`..`

5.如果oldname=newname，将无任何作用