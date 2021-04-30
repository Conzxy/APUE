# File I/O

* 本章所讲为unbuffered I/O（read，write调用内核系统调用），相对于第五章的standard I/O

## file descriptor

概念：非负整数，所有打开的文件都有一个fd

每个进程都有3个标准IO设备与之关联，但实际unix一切皆是文件，因此是与3个fd绑定在一起

| standard IO device | file descriptor | MACROS（<unistd.h>) |
| ------------------ | --------------- | ------------------- |
| stdin              | 0               | STDIN_FILENO        |
| stdout             | 1               | STDOUT_FILENO       |
| stderr             | 2               | STDERR_FILENO       |


