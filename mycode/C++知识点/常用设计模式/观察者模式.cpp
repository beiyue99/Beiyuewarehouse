#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

class Subject;

// 观察者基类
class Observer {
public:
    virtual ~Observer() {}
    // 更新方法，由具体的观察者实现
    virtual void update(Subject* subject) = 0;
};

// 主题类
class Subject {
private:
    std::vector<std::shared_ptr<Observer>> observers; // 观察者列表
    int state; // 主题状态

public:
    Subject() : state(0) {}

    // 添加观察者
    void attach(std::shared_ptr<Observer> observer) {
        observers.push_back(observer);
    }

    // 移除观察者
    void detach(std::shared_ptr<Observer> observer) {
        auto it = std::find(observers.begin(), observers.end(), observer);
        if (it != observers.end()) {
            observers.erase(it);
        }
    }

    // 通知观察者主题状态变化
    void notifyObservers() {
        for (const auto& observer : observers) {
            observer->update(this);
        }
    }

    // 设置主题状态并通知观察者
    void setState(int newState) {
        state = newState;
        notifyObservers();
    }

    // 获取主题状态
    int getState() const {
        return state;
    }
};

// 具体观察者类
class ConcreteObserver : public Observer {
private:
    std::string name; // 观察者名称

public:
    ConcreteObserver(const std::string& name) : name(name) {}

    // 更新方法，打印主题状态变化信息
    void update(Subject* subject) override {
        std::cout << name << ": 主题状态变化为 " << subject->getState() << std::endl;
    }
};

int main() {
    std::shared_ptr<Subject> subject = std::make_shared<Subject>(); // 创建主题对象
    std::shared_ptr<Observer> observer1 = std::make_shared<ConcreteObserver>("观察者1"); // 创建观察者1
    std::shared_ptr<Observer> observer2 = std::make_shared<ConcreteObserver>("观察者2"); // 创建观察者2

    subject->attach(observer1); // 将观察者1添加到主题中
    subject->attach(observer2); // 将观察者2添加到主题中

    subject->setState(1); // 设置主题状态为1
    subject->setState(2); // 设置主题状态为2

    subject->detach(observer1); // 将观察者1从主题中移除

    subject->setState(3); // 设置主题状态为3

    return 0;
}
