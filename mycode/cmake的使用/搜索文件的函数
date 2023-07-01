在CMake中使用aux_source_directory命令可以查找某个路径下的所有源文件, 命令格式为:
aux_source_directory(<dir> <variable >)
#dir : 要搜索的目录
#variable : 将从dir目录下搜索到的源文件列表存储到该变量中

aux_source_directory(${PROJECT_SOURCE_DIR} SRC)     PROJECT_SOURCE_DIR代表cmake后跟的路径，如果不用这个宏，需要手动指定路径






cmake_minimum_required(VERSION 3.15)
project(test)
#set(SRC add.cpp div.cpp mul.cpp main.cpp sub.cpp)
#aux_source_directory(${ PROJECT_SOURCE_DIR } SRC)
file(GLOB SRC ${ CMAKE_CURRENT_SOURCE_DIR/*.cpp})
set(EXECUTABLE_OUTPUT_PATH / mnt / c / Users / 北月 / OneDrive / 桌面 / codeLinux / exe)   把可执行文件放入指定目录exe下
set(CMAKE_CXX_STANDARD 11)
add_executable(app ${ SRC })  指定可执行文件名称




file(GLOB MAIN_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/ *.cpp)    #储存到SRC,CMAKE_CURRENT_SOURCE_DIR代表cmakelists.txt的路径
file(GLOB MAIN_HEAD ${CMAKE_CURRENT_SOURCE_DIR}/include/ *.h)
#当所有的.cpp文件和.h文件分别存放在不同的文件夹，那么执行make的时候，会报错：找不到这样的文件
#在CMke中设置要包含的目录也很简单,通过一个命令就可以搞定了,他就是include_directories:


cmake_minimum_required(VERSION 3.15)
project(test)
file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}src/*.cpp)
set(EXECUTABLE_OUTPUT_PATH /mnt/c/Users/北月/OneDrive/桌面/codeLinux/exe)   #把可执行文件放入指定目录exe下
set(CMAKE_CXX_STANDARD 11)
add_executable(app ${SRC})  #指定可执行文件名称
include_directories(${PROJECT_SOURCE_DIR}/include)