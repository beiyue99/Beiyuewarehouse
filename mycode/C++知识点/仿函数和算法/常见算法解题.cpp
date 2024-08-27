//翻转链表，翻转 m,n之间的节点。首先找到m前驱节点pre，然后让cur位于m节点
//循环m-n次，每次让tmp=cur的next,然后执行三个语句：
// 1.   cur->next=tmp->next    2.  tmp->next=pre->next  3.pre->next=tmp
//







//翻转栈
#include <iostream>
#include <stack>

// 辅助函数：将一个元素插入到栈的底部
void insertAtBottom(std::stack<int>& stack, int item) {
    if (stack.empty()) {
        // 如果栈为空，直接将元素压入栈
        stack.push(item);
    }
    else {
        // 弹出栈顶元素并暂存
        int top = stack.top();
        stack.pop();
        // 递归地将元素插入到剩余栈的底部
        insertAtBottom(stack, item);
        // 将暂存的栈顶元素重新压回栈中
        stack.push(top);
    }
}
// 主递归函数：翻转栈
void reverseStack(std::stack<int>& stack) {
    if (!stack.empty()) {
        int top = stack.top();
        stack.pop();
        reverseStack(stack);
        // 将弹出的元素插入到翻转后的栈底
        insertAtBottom(stack, top);
    }
}
// 打印栈中元素（用于测试）
void printStack(std::stack<int> stack) {
    while (!stack.empty()) {
        std::cout << stack.top() << " ";
        stack.pop();
    }
    std::cout << std::endl;
}

int main() {
    // 示例栈
    std::stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    std::cout << "初始栈: ";
    printStack(stack);
    // 翻转栈
    reverseStack(stack);
    std::cout << "翻转后的栈: ";
    printStack(stack);
    return 0;
}





//求全排列

void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len) {
    // 所有数都填完了
    if (first == len) {
        res.emplace_back(output);
        return;
    }
    for (int i = first; i < len; ++i) {
        // 动态维护数组
        swap(output[i], output[first]);
        // 继续递归填下一个数
        backtrack(res, output, first + 1, len);
        // 撤销操作
        swap(output[i], output[first]);
    }
}