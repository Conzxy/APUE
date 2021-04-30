# open/openat

```cpp
#include <fcntl.h>
//file control

int open(const char* path,int oflags);
int open(const char* path,int oflags,mode_t mode);
int openat(int fd,const char* path,int oflags,mode_t mode);
//return:fd if OK,-1 on error
```

| oflags   | description  |
| -------- | --------|
| O_RDONLY | read only   |
| O_WRONLY | write only   |
| O_RDWR   | read and write    |
| O_EXEC   | execute only    |
| O_SEARCH | search only(applies to directories) |

这五个只能有一个被指定（它们并不是按bit分开来的，因此O_RDONLY|O_WRONLY=O_RDWR不成立）

下面是可选标志：

| oflags      | effect                                                       |
| ----------- | ------------------------------------------------------------ |
| O_APPEND    | 每次在文件末进行写入                                         |
| O_CLOEXEC   | 设置FD_CLOEXEC文件描述标志                                   |
| O_CREAT     | 如果文件不存在创建该文件，需要指定mode：指定了新文件的访问权限位 |
| O_DIRECTORY | 如果path不是目录路径则产生错误                               |
| O_EXEL      | 与O_CREAT一起使用（原子操作，EXEL是exclusive的缩写），如果文件已存在产生错误 |
| O_NOCTTY    | 若打开的文件是终端设备，不让它作为该进程的控制终端（9.6）    |
| O_NOFOLLOW  | 如果path表示符号链接产生错误（4.17）                         |
| O_NONBLOCK  | 14.2                                                         |
| O_SYNC      | 每次写入需要等待物理IO完成                                   |
| O_TRUNC     | 如果文件存在并且成功以只写或是读写打开，截断该文件           |
| O_TTY_INIT  | 18                                                           |

同步输入和输出（POSIX.1）

| oflags  | effect |
| ------- | ------ |
| O_DSYNC |        |
| O_RSYNC |        |

## open与openat的差异

区别在于fd参数

* 如果path是绝对路径，则两者行为一致
* 如果path是相对路径

## 习惯问题
不要这么写：
```cpp
int fd;
if(fd=open(pathname,oflags) < 0)   //wrong
//< 的优先级高于=，所以fd为0或1
//---
int fd=open(pathname,oflags);
if(fd < 0)          //good
```

