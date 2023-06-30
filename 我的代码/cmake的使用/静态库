

#在cmake中,如果要制作静态库,需要使用的命令如下:
add_library(库名称 STATIC 源文件1 [源文件2] ...)     #如果是动态库 ，指定SHARE

set(LIBRARY_OUTPUT_PATH /home/dabing/abcdefg) #指定生成库的路径



#制作静态库
cmake_minimum_required(VERSION 3.15)
project(test)
file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
include_directories(${PROJECT_SOURCE_DIR}/include)
set(LIBRARY_OUTPUT_PATH /mnt/c/Users/北月/OneDrive/桌面/codeLinux/library)
add_library(calc SHARED ${SRC})




#链接静态库
link_libraries(<static lib>[<static lib>...])
参数1:指定出要链接的静态库的名字
可以是全名Libxxx.a
也可以是掐头去尾之后的名字XxX
参数2-N:要链接的其它静态库的名字
如果该静态库不是系统提供的(自己制作或者使用第三方提供的静态库)
可能出现静态库找不到的情况,此时可以将静态库的路径也指定出来:
Link_directories(<lib path>)





#链接使用静态库
cmake_minimum_required(VERSION 3.15)
project(test)
file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
include_directories(${PROJECT_SOURCE_DIR}/include)
link_libraries(calc)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib1)
set(EXECUTABLE_OUTPUT_PATH /mnt/c/Users/北月/OneDrive/桌面/codeLinux/exe)
add_executable(app ${SRC})
