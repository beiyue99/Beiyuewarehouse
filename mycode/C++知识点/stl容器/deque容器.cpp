#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<deque>
#include<algorithm>
#include<vector>
#include<ctime>







//安全队列
#include <queue>
#include <mutex>
#include <condition_variable>
template <typename T>

class ThreadSafeQueue {
private:
    std::queue<T> queue_;
    std::mutex mutex_;
    std::condition_variable condition_;

public:
    ThreadSafeQueue() = default;
    ThreadSafeQueue(const ThreadSafeQueue& other) = delete;
    ThreadSafeQueue& operator=(const ThreadSafeQueue& other) = delete;
    ~ThreadSafeQueue() = default;

    void push(T new_value) {
        std::unique_lock<std::mutex> lock(mutex_);
        queue_.push(new_value);
        lock.unlock();
        condition_.notify_one();
    }

    T pop() {
        std::unique_lock<std::mutex> lock(mutex_);
        while (queue_.empty()) {
            condition_.wait(lock);   //如果为空一直等待，也可以定义别的行为
        }
        T rc(std::move(queue_.front()));
        //将指针或资源所有权从一个对象转移到另一个对象，而不需要复制整个对象的内容
        //使用 std::move() 是为了避免拷贝构造函数的调用，提高性能。
        queue_.pop();
        return rc;
    }

    bool empty() const {
        std::lock_guard<std::mutex> lock(mutex_);
        return queue_.empty();
    }
};









