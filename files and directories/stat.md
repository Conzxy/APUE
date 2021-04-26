# stat
```cpp
#include <sys/stat.h>

int stat(char const* restrict pathname,struct stat* restrict buf);

int fstat(int fd,struct stat* restrict buf);

int lstat(char const* restrict pathname,struct stat* restrict buf);

int fstatat(int fd,char const* restrict pathname,struct stat* restrict buf,int flag);

//return: 0 if OK,-1 on error
```
> lstat=symbolic link stat,当路径表示符号链接文件时，返回的是符号链接本身的信息，而非被符号链接引用的文件信息

> fstatat要考虑两个参数：fd和flag
> * 当flag为AT_SYMLINK_NOFOLLOW时，表示返回符号链接本身信息，否则默认返回符号链接引用的文件信息（即根据flag可以变成stat，lstat） 
> * 如果fd为AT_FDCWD，且路径为相对路径时，那么将会把路径评估为当前目录的相对路径。当路径为绝对路径时，忽略该fd

```cpp
struct stat
{
    mode_t      st_mode;    //file type & mode
    ino_t       st_ino;     //i-node number
    dev_t       st_dev;     //device number(file system)
    dev_t       st_rdev;    //device number for special files
    nlink_t     st_nlink;   //number of links
    uid_t       st_uid;     //user ID of owner
    gid_t       st_gid;     //group ID of owner
    off_t       st_size;    //size in bytes,for regular file
    struct timespec st_atime;   //time of last acess
    struct timespec st_mtime;   //time of last modification
    struct timespec st_ctime;   //time of last file status change;
    blksize_t       st_blksize; //best I/O block size
    blkcnt_t        st_blocks;  //numberof disk blocks allocated
};
```