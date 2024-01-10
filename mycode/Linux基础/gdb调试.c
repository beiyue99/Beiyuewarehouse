int main(int argc,char**argv)   //主函数可以带参数

(gdb) set args 10 20 30 40     //设置参数 show args可以显示出设置的参数


start命令            //执行第一行，再输入continue命令执行到第一个断点处

argc=传入的参数个数+1      argv[0]代表当前可执行代码的绝对路径，然后分别代表设置的参数

list(l)命令用来显示源代码  list默认显示当前行后的10行，list-显示行前  list 1 代表从第一行开始显示 list main 代表显示主函数  set listsize 20 设置默认显示20行

break(b)命令用于设置断点，b 10代表设置断点在第10行  b main代表在主函数设置断点
delete(d)命令用于删除断点  d 10-12 闭区间删除断点的序号
disable 12  禁用序号为12的断点    enable 12  启用序号为12的断点
info和break都可以简写 info b是显示断点

run执行到第一个断点处

p命令可以显示变量的值

display i   //每次执行都显示i的值 
disable display  1 或者enable是禁用或恢复序号为1的显示.  undisplay  1是删除该序号

ptype i  //查看i的数据类型      set var i=100  //设置i的值为100
