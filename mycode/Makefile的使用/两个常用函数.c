Makefile中两个常用的函数：
1. wildcard  查找指定目录下指定类型的文件
2. patsubst  匹配替换

//  1 SRC=$(wildcard ./*.c)
//  2 OBJS = $(patsubst %.c,%.o,$(SRC))  将src里所有后缀为.c的文件替换为.o
//  3 %.o:%.c
//  4     gcc -c $< -o $@
//  5 test:$(OBJS)
//  6     gcc $(OBJS) -o $@ 
//  7 clean:
//  8     rm -rf $(OBJS)