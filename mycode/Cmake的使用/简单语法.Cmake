#是cmake里面的注释     #[[   ]]  这是多行注释



#cmake_minimum_required:指定使用的cmake的最低版本





#add_executable(app add.c div.c main.c mult.c sub.c)
#add_executable(app add.c; div.c; main.c; mult.c; sub.c)




#最简单的cmake：
cmake_minimum_required(VERSION 3.15)
project(test)
add_executable(app add.cpp div.cpp mul.cpp main.cpp sub.cpp)

