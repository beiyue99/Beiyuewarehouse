
queue:
push(value)：将元素入队。
pop()：将队首元素出队。
front()：返回队首元素的引用。
back()：返回队尾元素的引用。
empty()：如果队列为空，则返回 true，否则返回 false。
size()：返回队列中元素的数量。


deque容器：
push_back(value)：在尾部插入一个元素。
push_front(value)：在头部插入一个元素。
pop_back()：删除尾部的元素。
pop_front()：删除头部的元素。
front()：返回头部元素的引用。
back()：返回尾部元素的引用。
at(index)：返回指定索引处的元素的引用
size()：返回容器中元素的数量。
empty()：如果容器为空则返回 true，否则返回 false。
clear()：删除容器中的所有元素，使其成为空容器。
insert(iterator, value)：在指定位置插入一个元素。
erase(iterator)：删除指定位置的元素。
std::find()：在容器中查找指定值的元素。



栈：
push(value)：将元素压入栈顶。
pop()：弹出栈顶元素。
top()：返回栈顶元素的引用，但不会移除该元素。
empty()：如果栈为空，则返回 true，否则返回 false。
size()：返回栈中元素的数量。