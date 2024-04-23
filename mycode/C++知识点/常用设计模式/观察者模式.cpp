#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

class Subject;

// �۲��߻���
class Observer {
public:
    virtual ~Observer() {}
    // ���·������ɾ���Ĺ۲���ʵ��
    virtual void update(Subject* subject) = 0;
};

// ������
class Subject {
private:
    std::vector<std::shared_ptr<Observer>> observers; // �۲����б�
    int state; // ����״̬

public:
    Subject() : state(0) {}

    // ��ӹ۲���
    void attach(std::shared_ptr<Observer> observer) {
        observers.push_back(observer);
    }

    // �Ƴ��۲���
    void detach(std::shared_ptr<Observer> observer) {
        auto it = std::find(observers.begin(), observers.end(), observer);
        if (it != observers.end()) {
            observers.erase(it);
        }
    }

    // ֪ͨ�۲�������״̬�仯
    void notifyObservers() {
        for (const auto& observer : observers) {
            observer->update(this);
        }
    }

    // ��������״̬��֪ͨ�۲���
    void setState(int newState) {
        state = newState;
        notifyObservers();
    }

    // ��ȡ����״̬
    int getState() const {
        return state;
    }
};

// ����۲�����
class ConcreteObserver : public Observer {
private:
    std::string name; // �۲�������

public:
    ConcreteObserver(const std::string& name) : name(name) {}

    // ���·�������ӡ����״̬�仯��Ϣ
    void update(Subject* subject) override {
        std::cout << name << ": ����״̬�仯Ϊ " << subject->getState() << std::endl;
    }
};

int main() {
    std::shared_ptr<Subject> subject = std::make_shared<Subject>(); // �����������
    std::shared_ptr<Observer> observer1 = std::make_shared<ConcreteObserver>("�۲���1"); // �����۲���1
    std::shared_ptr<Observer> observer2 = std::make_shared<ConcreteObserver>("�۲���2"); // �����۲���2

    subject->attach(observer1); // ���۲���1��ӵ�������
    subject->attach(observer2); // ���۲���2��ӵ�������

    subject->setState(1); // ��������״̬Ϊ1
    subject->setState(2); // ��������״̬Ϊ2

    subject->detach(observer1); // ���۲���1���������Ƴ�

    subject->setState(3); // ��������״̬Ϊ3

    return 0;
}
