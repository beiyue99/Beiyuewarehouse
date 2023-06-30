

#动态库的使用  这个函数也可以链接静态库
target_link_libraries(
<target>
<PRIVATE|PUBLIC|INTERFACE><item>...
[<PRIVATE|PUBLIC|INTERFACE><item>...]...)
target:指定要加载动态库的文件的名字
PRIVAT|PUBLIC|INTERFACE:动态库的访问权限,默认为PUBLIC
如果各个动态库之间没有依赖关系,无需做任何设置,三者没有没有区别,一般无需指定,使用默认的PUBLIC即可。



动态库的链接具有传递性,如果动态库A链接了动态库B、C,动态库D链接了动态库A,此时动态库D相当于也链接了动态库B、C,
并可以使用动态库B、C中定义的方法。如果BC使用的私有方法，那么只有A可以使用BC中的函数，D只能使用A的函数而不能使用BC的函数

target_link_libraries(A B C)
target_link_libraries(D A)

PUBLIC: 在public 后面的库会被Link到前面的target中,并且里面的符号(库函数)也会被导出,提供给第三方使用。
PRIVATE:在private后面的库仅被Link到前面的target中,并且终结掉,第三方不能感知你调了啥库
INTERFACE:在interface后面引入的库不会被链接到前面的target中,只会导出符号。
最后者隐私性更强，使得A库不知道有 BC的存在，只是知道里面的函数




在target._Link_libraries(app pthread)中:
app:对应的是最终生成的可执行程序的名字
pthread:这是可执行程序要加载的动态库,这个库是系统提供的线程库



cmake_minimum_required(VERSION 3.15)
project(test)
file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib2)
set(EXECUTABLE_OUTPUT_PATH /mnt/c/Users/北月/OneDrive/桌面/codeLinux/exe)
add_executable(app ${SRC})
target_link_libraries(app calc)
