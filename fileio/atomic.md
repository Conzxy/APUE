# 原子操作

## pread/pwrite

```cpp
#include <unistd.h>
ssize_t pread(int fd,void* buf,size_t nbytes,off_t offset);
//return:number of bytes read,0 if end of file,-1 on error

ssize_t pwrite(int fd,const void* buf,size_t nbytes,off_t offset);
//return:number of bytes written if OK,-1 on error
```

> pread等价于调用lseek+read，但是这两个操作是原子的并且当前文件偏移并不会更新（更可控）

## 创建文件

使用O_CREATE和O_EXCL标志打开文件，其检查文件是否存在和创建文件是原子操作

不然我们可能会这样写：

```cpp
if((fd=open(path,O_WRONLY))<0)
{
    if(errno == ENOENT)
    {
        if((fd=create(path,mode))<0)
            err_sys("create error");
    }
    else{
        err_sys("open error");
    }
}
```

## dup/dup2

```cpp
#include <unistd.h>
int dup(int oldfd);
int dup2(int oldfd,int newfd);
//return:new fd if OK,-1 on error
```

> 如果new fd已经打开，则先关闭它；如果old fd ≠ new fd，则new fd的FD_CLOEXEC标志清空

![image-20210417085830658.png](https://i.loli.net/2021/04/25/6LgDqderhs8TU1x.png)
