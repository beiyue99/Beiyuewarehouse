


#include <iostream>

// ���Խӿ�
class Strategy {
public:
    virtual ~Strategy() {}
    virtual void execute() const = 0;
};

// �������1
class ConcreteStrategy1 : public Strategy {
public:
    void execute() const override {
        std::cout << "Executing strategy 1." << std::endl;
    }
};

// �������2
class ConcreteStrategy2 : public Strategy {
public:
    void execute() const override {
        std::cout << "Executing strategy 2." << std::endl;
    }
};

// ��������
class Context {
private:
    Strategy* strategy;

public:
    Context(Strategy* strategy) : strategy(strategy) {}

    // ���ò���
    void setStrategy(Strategy* newStrategy) {
        strategy = newStrategy;
    }

    // ִ�в���
    void executeStrategy() const {
        strategy->execute();
    }
};

int main() {
    // ����������Զ���
    Strategy* strategy1 = new ConcreteStrategy1();
    Strategy* strategy2 = new ConcreteStrategy2();

    // ���������Ķ��󣬲����ò���
    Context context(strategy1);
    context.executeStrategy();

    // �л�����
    context.setStrategy(strategy2);
    context.executeStrategy();

    // �ͷ��ڴ�
    delete strategy1;
    delete strategy2;

    return 0;
}