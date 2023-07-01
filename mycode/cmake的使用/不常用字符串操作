


#下面皆为不常用函数，了解即可

获取ist的长度
list(LENGTH <list> <output variable>)

LENGTH:子命令LENGTH用于读取列表长度
<L1st>:当前操作的列表
<output variable>:新创建的变量,用于存储列表的长度。




#读取列表中指定索引的的元素，可以指定多个索引
list(GET <list><element index>[<element index>..<output variable>)
<L1st>:当前操作的列表
<element index>:列表元素的索引
从0开始编号,索引0的元素为列表中的第一个元素;
索引也可以是负数,-1表示列表的最后一个元素,-2表示列表倒数第二个元素,以此类推
当索引(不管是正还是负)超过列表的长度,运行会报错
<output variable>:新创建的变量,存储指定索引元素的返回结果,也是一个列表。




#将列表中的元素用连接符(字符串)连接起来组成一个字符串
#假设原有 123；23   指定glue为xxx   操作后： 123xxx23
list (JOIN <list><glue><output variable>)
<List>:当前操作的列表
<gUe>:指定的连接符(字符串)
<output variable>:新创建的变量,存储返回的字符串






#查找列表是否存在指定的元素,若果末找到,返回-1
list(FIND <list><valve> output variable>)
<list>:当前操作的列表
<valve>:需要再列表中搜索的元素
<output variable>:新创建的变量








#在st中指定的位置插入若干元素

list(INSERT <list> <element_index> <element>[<element>..])




#头插

list(PREPEND <list> [<element>...])




# 尾删：POP_BACK
# 头删: POP_FRONT 
# 去重：REMOVE_DUPLICATES
# 翻转：REVERSE


#排序
list(SORT <list>[COMPARE <compare>][CASE <case>][ORDER <order>])

COMPARE:指定排序方法。有如下几种值可选:
   STRING:按照字母顺序进行排序,为默认的排序方法
   FILE_BASENAME:如果是一系列路径名,会使用basename进行排序
   NATURAL:使用自然数顺序排序
CASE:指明是否大小写敏感。有如下几种值可选:
   SENSITIVE:按照大小写敏感的方式进行排序,为默认值
   INSENSITIVE:按照大小写不敏感方式进行排序
ORDER:指明排序的顺序。有如下几种值可选:
   ASCENDING:按照升序排列,为默认值
   DESCENDING:按照降序排列