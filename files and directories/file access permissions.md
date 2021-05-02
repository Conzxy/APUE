# 文件访问权限
|st_mode mask|description|
|------------|-------|
|S_ISUID    |set-user-ID|
|S_ISGID    |set-group-ID|
|S_ISVTX    |sticky bit|
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
* permission:r,w,x,s(set-user-ID-bit)
## rules
* 无论何时，打开一个文件，**都必须拥有路径中出现的所有目录的执行权限**
* 目录的读权限意味着可以获取该目录下所有的文件名，
  而目录的执行权限意味着可以经由这个目录来进行对该目录下文件的访问
* 读权限决定了是否可以打开一个文件用于read：open(..,`O_RDONLY/O_RDWR`)
* 写权限决定了是否可以打开一个文件用于write:open(..,`O_WRONLY/O_RDWR`)
* 指定`O_TRUNC`必须要有写权限
* 在目录中**创建**一个新文件需要有该目录的**写权限和执行权限**
* **删除**目录中的文件同样也需要该目录的**写权限和执行权限**。对于该文件我们并不需要读写权限
* 如果要通过exec()执行文件必须要有执行权限且该文件必须为rugular file
## file access test
当进程**打开，创建，删除**一个文件时，内核会进行文件访问测试，依赖于文件的拥有者（st_uid和st_gid)，effective IDs，supplementary group ID。
* 如果进程的effective ID为0(root)，允许访问
* 如果进程的effective user ID与文件的拥有者相同，根据适当的访问权限位进行访问：
  * read -> user read bit
  * write -> user write bit
  * execute -> user execute bit
如果执行相应操作的访问权限位没有设置，则拒绝访问
* 如果进程的effective group ID或supplementary group ID与文件的group ID相同。根据适当的访问权限位进行访问，同上
* 如果适当的other访问权限位设置，允许访问
（基本上就是先看ID匹配再看访问权限位）
> 以上four step是具有短路效应的，如果第二步确实ID与拥有者相同（即该进程拥有该文件），其访问取决于访问权限位，而不会继续考虑后面的step
> （应该是优先级导致的：root > user > group > other，如果user没有读权限，group和other也没有必要考虑了）

> 对于access 和 faccessat(unset AT_EACCESS) 将four steps中的effective ID换成real ID
