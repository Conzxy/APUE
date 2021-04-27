# 新文件和新目录的拥有权
新文件的user ID设为进程的effective user ID
新文件的group ID根据POSIX.1有两种选择：
* 设为进程的effective group ID
* 创建所在的目录的group ID
