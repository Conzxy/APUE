# 文件系统
这里不作十分深入的研究
这里要讨论的文件系统是**Berkeley fast file system**

## 结构
![image.png](https://i.loli.net/2021/04/30/fCIT6eSpMm9X5dN.png)
* partition：包含一个文件系统的分区
* super block：记录文件系统的特定信息，比如inode表的起始位置，inode和数据块的数量，标识文件类型的image number等
* super block copy：super block的备份，保证super block损坏了依然可以加载信息
* i-node map和block bitmap：记录inode和data block的使用情况
* i-nodes：inode表，放置inode
* data blocks：数据块存放的地方

## hard link
![image.png](https://i.loli.net/2021/04/30/TGnhg5qQSMPO1sB.png)

data block中还包含有directory block，每个条目记做一个二元组`(inode number,filename)`（以下都将directory block entry记做DBE）
图中可以看出，有两个DBE指向同一个inode，每个inode都会有一个`link count`记录有多少个DBE指向它，当链接计数归0时，才会删除该文件。这也是`rm`指令做的事情，即`unlink`
这种链接称为`hard link`，回想stat结构体，有个st_nlink成员（类型为nlink_t），它记录对应inode1的硬链接计数
注意硬链接不能跨文件系统，因为inode在同一个文件系统，但符号链接没有这个约束

## symbolic link
`符号链接`不像硬链接那样建立链接计数关系，而是仅仅记录指向的文件名在符号链接中，如下
```
lrwxrwxrwx 1 root 7 Sep 25 07:14 lib -> usr/lib
```
其中7就是usr/lib的长度（不包含终止符）
需要注意的是符号链接是一种文件类型，文件系统通过`S_IFLNK`识别

## inode
inode=index node
包含文件类型，文件访问权限位，文件大小，指向数据块的直接指针和间接指针等

## DBE
DBE包含文件名，inode号（ino_t），filename长度以及目录记录长度

## 栗子
```
$ mkdir testdir
```

![image.png](https://i.loli.net/2021/04/30/gwnzmIMtrPGOU1R.png)

每个目录块中必然会有两个DBR：`.`和`..`，分别表示当前目录和父目录
由图不难得出：1267/testdir
因此testdir有两个链接计数：一个是1267中的DBE，另一个是testdir的`.`
```
rm -r testdir
```
则将所有DBE清除，链接计数归0，回收该目录块
