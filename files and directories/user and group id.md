# set-user-id /set-group-id
| ID            | description|
|-----------    |------------|
|real user ID   |真实ID|
|real group ID  |取自password file      |
|effective user ID| 用于文件访问权限的检验|
|effective group ID||
|supplementary group ID||
|saved set-user-ID|被exec()保存|
|saved set-group-ID|包含effective-ID的拷贝|

> 每个文件都有owner，由`st_uid`和`st_gid`指定

> 通常，effective ID=real ID，但是可以设置set-user-ID bit和set-group-ID bit（包含在mode中），从而实现实现：“当文件执行时，设置effective user ID为文件的owner(st_u/gid)”
> 这两个bit的flag为`S_ISUID`,`S_ISGID`
