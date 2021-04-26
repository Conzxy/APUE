# 文件访问权限
|st_mode mask|meaning|
|------------|-------|
|S_IRUSR    |user-read|
|S_IWUSR    |user-write|
|S_IXUSR    |user-execute|
|S_IRGRP    |group-read|
|S_IWGRP    |group-write|
|S_IXGRP    |group-execute|
|S_IROTH    |other-read|
|S_IWOTH    |other-write|
|S_IXOTH    |other-execute|

终端下chmod指令可以修改访问权限
`chmod [who] operator [permission] filename`
* who:u-user,g-group,o-other,a-all（可组合使用）
* operator:+,-,=(set)
* permission:r,w,x,s

