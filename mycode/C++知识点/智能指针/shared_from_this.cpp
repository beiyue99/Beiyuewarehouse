
class MyClass : public std::enable_shared_from_this<MyClass> {
public:
    MyClass() {
        std::cout << "Constructing MyClass " << std::endl;
    }

    void printShared() {
        std::shared_ptr<MyClass> sharedPtr = shared_from_this();
        std::cout << "Use count: " << sharedPtr.use_count() << std::endl;
    }

    ~MyClass() {
        std::cout << "Destructing MyClass" << std::endl;
    }
};

int main() {
    std::shared_ptr<MyClass> ptr1 = std::make_shared<MyClass>();  //ptr1 �����������ü���Ϊ1��
    // �ڶ����ڲ����� shared_from_this() ��ȡ���������� shared_ptr
    ptr1->printShared();  //shared_from_this() ��ȡ��һ���µ�std::shared_ptr�����������ü�������ʱ���ü���Ϊ2��
    std::cout << "External use count: " << ptr1.use_count() << std::endl;  //  �ⲿ��� ptr1.use_count()�����ü���Ϊ1��
    //��Ϊ�� printShared�л�õ� sharedPtr ��������������������ٵġ�
    // ���ⲿ�ٴλ�ȡ shared_ptr
    std::shared_ptr<MyClass> ptr2 = ptr1->shared_from_this();
    //ptr2 �����������ü�������Ϊ2��
    std::cout << "External use count after second shared_ptr creation: " << ptr1.use_count() << std::endl;  //  2

    ptr1->printShared();  //�ٴλ�ȡ�� std::shared_ptr�����ü�������Ϊ3�� 
    return 0;
}







class Register;

class login : public std::enable_shared_from_this<login> {
public:
    void initSignals();

private:
    std::shared_ptr<Register> _register;
};

class Register {
public:
    void set_login(std::shared_ptr<login> loginPtr) {
        _login = loginPtr;
    }

private:
    std::shared_ptr<login> _login;
};

void login::initSignals() {
    _register = std::make_shared<Register>();
    //_register->set_login(this);  
    //this ָ������ָ�룬���������ᵼ����������������ָ�����������ͬһ�����󣬿��ܻᵼ�¶����ظ�����

    //_register->set_login(std::shared_ptr<login>(this)); // ��Ҳ�Ǵ���ģ��ᵼ�¶���Ķ�������
    //�µ� std::shared_ptr<login> ӵ���Լ������ü�����
    //_login ����һ�� std::shared_ptr<login> ����ӵ���Լ������ü�����
    //set_login�������غ�����ֲ������� std::shared_ptr<login> ����ᱻ����
    //    ���������ִ��ʱ���������� std::shared_ptr<login> �����е�һ�������ͷŶ�����ڴ�ʱ��
    //    ������һ�� std::shared_ptr<login> ��Ȼ��ʹ�ö��󣬻ᵼ�¶���Ķ������������ܻᵼ��δ������Ϊ��
    _register->set_login(shared_from_this());
    // ��ȷ������������һ����ǰ�������ָ��,ǰ�����Ѿ���һ������ָ��������˹���
}

int main() {
    std::shared_ptr<login> loginPtr = std::make_shared<login>();
    loginPtr->initSignals();

    return 0;
}
