
#定义一个变量, 将文件名对应的字符串存储起来, 在cmake里定义变量需要使用set。
#[]中的参数为可选项, 如不需要可以不写
SET(VAR[VALUE][CACHE TYPE DOCSTRING[FORCE]])
VAR:变量名
VALUE : 变量值

set(SRC_LIST add.c div.c main.c mult.c sub.c)
add_executable(app ${SRC_LIST})


#增加 - std = c + 17
1.在CMakeLists.txt中通过set命令指定
set(CMAKE_CXX_STANDARD 17)    
2 在执行cmake命令的时候指定出这个宏的值
cmake CMakeLists.txt文件路径 - D CMAKE_CXX_STANDARD = 17



在CMake中指定可执行程序输出的路径, 也对应一个宏, 叫做EXECUTABLE_OUTPUT_PATH, 它的值还是通过set命令进行设置:
set(HOME /home/robin/Linux/Sort)
set(EXECUTABLE_OUTPUT_PATH  ${HOME}/bin)   #输出到home目录下的bin目录，如果指定的路径不存在，会自动创建




cmake_minimum_required(VERSION 3.15)
project(test)
set(SRC add.cpp div.cpp mul.cpp main.cpp sub.cpp)
set(EXECUTABLE_OUTPUT_PATH /mnt/c/Users/北月/OneDrive/桌面/codeLinux/exe)   把可执行文件放入指定目录exe下
set(CMAKE_CXX_STANDARD 11)
add_executable(app ${ SRC })  指定可执行文件名称
