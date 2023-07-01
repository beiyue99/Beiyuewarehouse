

在CMake中可以用用户显示条消息,该命令的名字为message:
message([STATUSI WARNING AUTHOR_WARNING |FATAL_ERROR
SEND_ERROR]"message to display"...)
(无):重要消息
STATUS:非重要消息
WARNING:CMake警告,会继续执行
AUTHOR_NARNING:CMake警告(deV),会继续执行
SEND_ERROR:CMake错误,继续执行,但是会跳过生成的步骤
FATAL_ERROR:CMake错误,终止所有处理过程






set(变量名 ${变量名1}${变量名2}..)
关于上面的命令其实就是将从第二个参数开始往后所有的字符串进行拼接,最后将结果存储到第一个参数中,如果第
一个参数中原来有数据会对原数据就行覆盖。






如果使用List进行字符串拼接,对应的命令格式如下:
list(APPEND <list> [<element>...])
1ist命令的功能比set要强大,字符串拼接只是它的其中一个功能,所以需要在它第一个参数的位置指定出我们
要做的操作,APPEND表示进行数据加,后边的参数和set就一样了。



我们在通过file搜索某个目录就得到了该目录下所有的源文件,但是其中有些源文件并不是我们所需要的,比如:
main.cpp是一个测试文件。此时,就需要将
main.cpp从搜索到的数据中剔除出去,想要实现这个功能,也可以使用List

list(REMOVE_ITEM <list><valve>[<valve>...])




set(tmp hello world)
set(tmp1 ${tmp} ${SRC})
message(${tmp1})


list(APPEND tmp "xxx1" "ssss2" ${SRC})
message(${tmp})




#删除main.cpp
list(REMOVE_ITEM SRC main.cpp)
这样不行，因为$(SRC)取出来的是绝对路径

list(REMOVE_ITEM SRC ${PROJECT_SOURCE_DIR}/src/main.cpp)