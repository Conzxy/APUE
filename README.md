该仓库记录APUE笔记，包括unix设计和API

## FileIO
|[creat](fileio/create-close.md)|[open](fileio/open.md)|
|:-----|:---- |
|[close](fileio/create-close.md)| [lseek](fileio/lseek.md)|
| [read](fileio/read-write.md) |[write](fileio/read-write.md)|

原子操作：

|[pread](fileio/atomic.md) |[pwrite](fileio/atomic.md)|
|:-|:-|
| [dup](fileio/atomic.md) | [dup2](fileio/atomic.md) |
| fcntl| |

## files & directories
文件信息
| [access](files%20and%20directories/access.md)| [stat](files%20and%20directories/stat.md)| [umask](files%20and%20directories/umask.md)| [chmod](files%20and%20directories/chmod.md) | [chown](files%20and%20directories/chown.md)|
|--|--|--|--|--|

文件截断

|[truncate](files%20and%20directories/truncate.md)|
|--|

硬链接

|[link](files%20and%20directories/link.md)|[unlink](files%20and%20directories/unlink.md)|[remove](files%20and%20directories/remove.md)|
|--|--|--|

重命名
|[rename](files%20and%20directories/rename.md)|
|--|

符号链接

|[symlink](files%20and%20directories/symlink.md)|[readlink](files%20and%20directories/readlink.md)|
|--|--|

文件时间

|[futimens](files%20and%20directories/futimens.md)|[utimes](files%20and%20directories/utimes.md)|
|--|--|

目录

|[mkdir](files%20and%20directories/mkdir.md)|[rmdir](files%20and%20directories/rmdir.md)|
|:-----|:-------|
|[opendir](files%20and%20directories/opendir.md)|[closedir](files%20and%20directories/opendir.md)|
|[readdir](files%20and%20directories/opendir.md)|[rewinddir](files%20and%20directories/opendir.md)|
|[seekdir](files%20and%20directories/opendir.md)|[telldir](files%20and%20directories/opendir.md)|