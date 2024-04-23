




1 test:add.c sub.c test.c
2     gcc add.c sub.c test.c - o test
调用make命令, 可直接生成test可执行文件.缺点，改动其中一个add.c 整个都需要重新编译






1 test:add.o sub.o test.o
2     gcc add.o sub.o test.o - o test
3 add.o : add.c
4     gcc - c add.c - o add.o
5 sub.o : sub.c
6     gcc - c sub.c - o sub.o
7 test.o : test.c
8     gcc - c test.c - o test.o
改进了第一个版本的缺点，如果改动其中一个文件，只需要重新编译该文件，别的文件不会动


除了自定义变量，系统有三个默认变量供我们使用
$@ 表示目标       $^ 表示所有的依赖    $< 表示第一个依赖 可以改为以下：
	1 OBJS = add.o sub.o test.o
	2 test:$(OBJS)
	3     gcc $(OBJS) - o $@
	4 add.o:add.c
	5     gcc - c $< -o $@
	6 sub.o:sub.c
	7     gcc - c $< -o $@
	8 test.o:test.c
	9     gcc - c $< -o $@


	可以在最后加上
	clean：
	rm - rf $(OBJS)  用来删除中间数据  make clean




	//模式匹配  使代码更精简
	OBJS = add.o sub.o test.o
	%.o:%.c
		gcc -c $< -o $@
	test:$(OBJS)
		gcc $(OBJS) -o $@
	clean:
		rm -rf $(OBJS)




	Makefile中两个常用的函数：
	1. wildcard  查找指定目录下指定类型的文件
	2. patsubst  匹配替换


	SRC = $(wildcard ./*.c)
	OBJS = $(patsubst %.c,%.o,$(SRC))
	#将src里所有后缀为.c的文件替换为.o
