


#include <iostream>

// 策略接口
class Strategy {
public:
    virtual ~Strategy() {}
    virtual void execute() const = 0;
};

// 具体策略1
class ConcreteStrategy1 : public Strategy {
public:
    void execute() const override {
        std::cout << "Executing strategy 1." << std::endl;
    }
};

// 具体策略2
class ConcreteStrategy2 : public Strategy {
public:
    void execute() const override {
        std::cout << "Executing strategy 2." << std::endl;
    }
};

// 上下文类
class Context {
private:
    Strategy* strategy;

public:
    Context(Strategy* strategy) : strategy(strategy) {}

    // 设置策略
    void setStrategy(Strategy* newStrategy) {
        strategy = newStrategy;
    }

    // 执行策略
    void executeStrategy() const {
        strategy->execute();
    }
};

int main() {
    // 创建具体策略对象
    Strategy* strategy1 = new ConcreteStrategy1();
    Strategy* strategy2 = new ConcreteStrategy2();

    // 创建上下文对象，并设置策略
    Context context(strategy1);
    context.executeStrategy();

    // 切换策略
    context.setStrategy(strategy2);
    context.executeStrategy();

    // 释放内存
    delete strategy1;
    delete strategy2;

    return 0;
}