#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<deque>
#include<algorithm>
#include<vector>
#include<ctime>







//��ȫ����
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
            condition_.wait(lock);   //���Ϊ��һֱ�ȴ���Ҳ���Զ�������Ϊ
        }
        T rc(std::move(queue_.front()));
        //��ָ�����Դ����Ȩ��һ������ת�Ƶ���һ�����󣬶�����Ҫ�����������������
        //ʹ�� std::move() ��Ϊ�˱��⿽�����캯���ĵ��ã�������ܡ�
        queue_.pop();
        return rc;
    }

    bool empty() const {
        std::lock_guard<std::mutex> lock(mutex_);
        return queue_.empty();
    }
};









