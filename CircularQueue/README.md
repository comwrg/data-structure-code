# Circlar Queue
## 遗留的疑问
这是听*郝斌*老师的数据结构写出的代码, 但关于判断队列是否已满有写疑问.</br>
课上讲的是两种方式:
1. 多增加一个表标识参数
2. 少用一个元素

但是我认为完全可以用 *front* 和 *rear* 之差是否等于队列的长度来判断队列是否已满. (详见 *main.c* )