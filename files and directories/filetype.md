# 文件类型
* regular file。大部分都是通常文件
* directory file。任何进程都有目录的读权限，但是只有内核才有目录的写权限。
* Block special file。提供以固定大小单元对设备的缓冲IO访问
* character special file。提供以不定大小单元对设备的非缓冲IO访问（所有的设备在系统中为block special file/character special file）
* FIFO。又称pipe，用于进程间通信
* Socket。用于进程间网络通信，也可以用于单个主机上的进程间非网络通信。
* symbolic link。指向其他文件的文件

文件类型会被包含在`st_mode`中，我们可以通过以下宏来检测：
|Macro|Type of file|
|-----|------------|
|S_ISREG|regular file|
|S_ISDIR|directory file|
|S_ISCHR|character file|
|S_ISBLK|Block file|
|S_ISFIFO|pipe or FIFO|
|S_ISLNK|symbolic link|
|S_ISSOCK|socket|
