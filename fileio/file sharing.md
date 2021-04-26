# 文件共享

内核用三个数据结构来表示打开的文件，它们之间的关系决定了文件共享中一个进程对另一个进程可能造成的作用

* process table entry：保存一个fd向量表，每个向量包括fd标志和指向file table entry的指针

* file table entry：保存文件状态标志，当前的文件偏移，指向该文件的v-node table entry的指针

* v-node table entry：保存v-node信息，和i-node

  v-node信息包含文件类型，对该文件进行操作的函数指针等

  i-node包含i-node信息，当前的文件大小，与之关联的v-node（i-vnode）

> 细节待补充

如下图所示：

![image-20210416215555280.png](https://i.loli.net/2021/04/25/v5JoQrWIYiDlp81.png)

## 打开同一个文件

![image-20210416220034435.png](https://i.loli.net/2021/04/25/5ZvJb3CFuHlRocN.png)

两个进程如果打开同一个文件，那么它们的file table entry会保存指向同一个v-node table entry，但是file table entry不是同一个，因为它们的文件状态标志和当前文件偏移是各自拥有的

这些数据结构与前面的操作也有关系：

* 每次write完成，当前文件偏移会增加为写入字节数，如果大于当前文件大小，则将i-node table entry的当前文件大小设置为当前文件偏移
* 如果文件是用O_APPEND标志打开，每次写入，当前文件偏移都会被设置为当前文件大小，以在文件末添加内容
* 如果文件是lseek定位当前文件末，也会设置当前文件偏移设置为i-node table entry中的当前文件大小，但是这个与O_APPEND打开是不同的（该方法并不原子）

* lseek仅仅修改当前文件偏移，不涉及I/O