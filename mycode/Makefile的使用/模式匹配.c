除了自定义变量，系统有三个默认变量供我们使用
$@ 表示目标       $^ 表示所有的依赖    $< 表示第一个依赖 以此可以改为以下：
	1 OBJS = add.o sub.o test.o
	2 test:$(OBJS)
	3     gcc $(OBJS) - o $@
	4 add.o:add.c
	5     gcc - c $ < -o $@
	6 sub.o:sub.c
	7     gcc - c $ < -o $@
	8 test.o:test.c
	9     gcc - c $ < -o $@





	//模式匹配  使代码更精简
	1 OBJS = add.o sub.o test.o
	2 % .o : % .c
	3     gcc -c $< -o $@
	4 test:$(OBJS)
	5     gcc $(OBJS) - o $@
