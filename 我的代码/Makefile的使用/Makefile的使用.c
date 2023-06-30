 

make默认在工作目录中寻找名为GUNmakefile、makefile、Makefile的文件作为输入文件    因此需要-f来指定别的文件
-w 命令用于显示工作目录      
make -C ./ -f 1.mk          -C用于指定工作路径
-n 只显示要执行的命令但不执行
-s 执行但不显示执行的命令
make test1 -f 1.mk   指定执行test1    如果不指定，默认执行终极目标all





1 test:add.c sub.c test.c
2     gcc add.c sub.c test.c -o test
调用make命令,可直接生成test可执行文件.缺点，改动其中一个add.c 整个都需要重新编译






1 OBJS = add.o sub.o test.o
2 test:$(OBJS)
3     gcc $(OBJS) - o test
自定义变量以使代码简洁
虽然在 Makefile 中没有为中间文件 add.o、sub.o 和 test.o 显式地定义编译规则，
但是由于 make 工具内置了一些默认规则，它们可以根据文件的扩展名来自动识别和执行适当的编译命令


可以在最后加上
clean：
rm - rf $(OBJS)  用来删除中间数据  make clean


1 test:add.o sub.o test.o
2     gcc add.o sub.o test.o -o test
3 add.o:add.c
4     gcc -c add.c -o add.o
5 sub.o:sub.c
6     gcc -c sub.c -o sub.o
7 test.o:test.c
8     gcc -c test.c -o test.o
改进了第一个版本的缺点，如果改动其中一个文件，只需要重新编译该文件，别的文件不会动



 
除了自定义变量，系统有三个默认变量供我们使用
1 $@ 表示目标      2 $^表示所有的依赖   3 $<表示第一个依赖 以此可以改为以下：
  1 OBJS = add.o sub.o test.o
  2 test:$(OBJS)
  3     gcc $(OBJS) -o $@ 
  4 add.o:add.c
  5     gcc -c $< -o $@
  6 sub.o:sub.c
  7     gcc -c $< -o $@
  8 test.o:test.c
  9     gcc -c $< -o $@
 10 clean:
 11     rm -rf $(OBJS)

//模式匹配  使代码更精简
  1 OBJS = add.o sub.o test.o
  2 %.o:%.c
  3     gcc -c $< -o $@
  4 test:$(OBJS)
  5     gcc $(OBJS) -o $@ 
  6 clean:
  7     rm -rf $(OBJS)



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
//
//
//如果当前目录有 clean文件，则不会执行Makefile中的clean 
//解决办法： .PHONY clean    将clean声明为伪目标    
//
//在前面加上@代表不显示过程，如:@gcc -c $< -o $@   
//
//
//
//gcc hello.c  -D SIZE=22       如果SIZE在程序中未被定义，那么可以用-D命令当做宏给它赋值
//                  
//                                                                                                                                                                                                               
//                         




FOO: = bar
BAZ : = $(FOO)
在这个例子中，当你定义BAZ变量时，它的值是$(FOO)。如果你在Makefile中引用BAZ变量，
它的值将是"bar"，因为$(FOO)在定义BAZ变量时已经被展开了。

另一方面，如果你使用“ = ”，而不是“： = ”进行变量定义，那么变量将被定义为递归变量，
即变量的值将在引用时进行展开。这意味着如果你在定义BAZ变量时使用“ = ”，那么它的值将是“$(FOO)”字符串，而不是“bar”。

因此，使用“： = ”赋值符号可以避免由于变量值的递归展开导致的Makefile错误，因为该变量的值将在定义时立即展开。




echo flag=$(FLAG)

make FLAG=123 -s      编译时传参，结果输出  flag=123




1 test:libaa.so
2     $(CC) test.c - o test - L. / -laa
3     sudo cp . / libaa.so / lib
4
5
6 libaa.so :
	7
	  8     $(CC) - FPIC - shared add.c sub.c - o libaa.so
	  9
	  10 clean :
	  11     $(RM) * .so test




	  TARGET 变量是一个自定义变量，你可以根据你的需求自由地定义它。在 Makefile 中，TARGET 变量通常用于指定要生成的可执行文件的名称，或者生成的库文件的名称。


	  LDFLAGS 变量通常用于指定链接器选项和库文件的路径，以便链接器可以正确地链接程序所需的库文件。


	  LIBS 变量通常用于指定要链接的库文件列表，可以包括系统提供的库文件和自定义的库文件。通过使用 LIBS 变量，
	  你可以轻松地指定需要链接的库文件，并且可以避免在每个链接器命令中都指定库文件名称。

	  将两个makefile里面重复的可以抽离出来，放到外面，在子文件的makefile  include一下就能用





	  1 FOO = a
	  2 BAR: = $(FOO)b
	  3 FOO = c
	  4
	  5 all :
	  6     @echo $(BAR)

	  输出ab   如果把 : = 换为 = 则输出cb



	  C = $(shell if[!- f $(FILE)]; then touch $(FILE); fi;)

	  echo $(shell for dir in $(DIR); do make - C $$dir clean; done)       其中 DIR 是几个目录



	  make&& make install
	  两个命令用 "&&" 连接在一起，这意味着只有在 "make" 命令成功执行后，才会继续执行 "make install" 命令。
	  这样可以确保只有在代码成功编译之后才会安装到系统中，以避免出现潜在的错误和问题。


	  把可执行文件 软连接到user / local / bin 就可以在任何目录执行




	TARGET = main

	$(TARGET) :
	$(CXX) - 1SoTest - L. / 001 - LaTest - L. / 002 main.cpp - o $(TARGE)





	可以改为：
	TARGET = main
	LDFLAGS = -L. / 001 - L. / 002
	LIBS = -lSoTest - laTest

	$(TARGET) :
	$(CXX)$(LDFLAGS) $(LIBS) main.cpp - o $(TARGET)







	ifeq($(A), 123)
	   RS1: = 123
	else
	   ifeq($(A), 321)
	      RS1: = 321
       else
          RS1: = n0 - 123 - 321
       endif
   endif






A: = $(shell ls .. /)
B: = $(shell pwd)
a :
	echo $(A)
	echo $(B)





	1 TARGET: = a b c d
	2 FILE : = $(foreach v, $(TARGET), $v.txt)      
	3
	4 all :
	5     echo $(TARGET)
	6     echo $(FILE)
	7
	8
	9 clean :
	10     $(RM) - rf $(TARGET) * txt
	11
	12.PHONY : all clean




	wjf@wjf - virtual - machine:~/ test$ make - s all
	a b c d
	a.txt b.txt c.txt d.txt








all:
    for v in $(TARGET); do \
		echo $$v; \                    (如果加上-n，则abcd输出在一行)
	done



		
1 TARGET: = a b c d
2 FILE : = $(foreach v, $(TARGET), $v.txt)
3
4 all :
5     for v in $(TARGET); do echo $$v; done;
6
7 clean:
8     $(RM) - rf $(TARGET) * txt
9
10.PHONY : all clean
如果你在 shell 命令中使用 $ 符号，Makefile 会将其解析为变量引用，而不是直接传递给 shell 执行。
为了让 $ 符号在 shell 命令中正常工作，需要将其转义为 $$。
因此，在 Makefile 的规则中，如果你想在 shell 命令中使用 $ 符号，就需要使用 $$ 来表示一个 $ 符号。









1 TARGET: = a b c d
2 FILE : = $(foreach v, $(TARGET), $v.txt)
3
4 all :
5     for v in $(TARGET); do touch $$v.txt; done;
6     $(shell for v in $(TARGET); do touch $$v - txt; done)
7
8 clean:
9     $(RM) - rf $(TARGET) * txt
10
11.PHONY : all clean



第5行中的for循环和touch命令属于Makefile规则的一部分，会在Makefile规则执行时被直接执行，
而第6行中的for循环和touch命令是一个由$(shell command)生成的shell命令，会在Makefile规则执行之前被执行





1 define FUNC1
2     echo func1
3 endef
4
5
6 all:
7     $(call FUNC1)            输出 func1







1 A: = 123
2 B : = $(A)
3 define FUNC1
4     echo $(1)$(2)$(3)
5 endef
6 A : = 456
7 all :
8     $(call FUNC1, abc, def, $(A))
9 A : = 789

//$(0) 0是自己的函数名






1 TARGET: = 006_main
2 OBJ : = $(TARGET).o
3 CC = g++
4
5
6 $(TARGET) : $(OBJ)


在没有定义规则的情况下，make将会使用其默认规则来构建可执行文件。
默认规则中，make会将目标名和依赖项名字相同的.o文件链接在一起，生成一个同名的可执行文件。













