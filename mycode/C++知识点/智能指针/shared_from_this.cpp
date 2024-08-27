
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
    std::shared_ptr<MyClass> ptr1 = std::make_shared<MyClass>();  //ptr1 被创建，引用计数为1。
    // 在对象内部调用 shared_from_this() 获取与对象关联的 shared_ptr
    ptr1->printShared();  //shared_from_this() 获取了一个新的std::shared_ptr，增加了引用计数，此时引用计数为2。
    std::cout << "External use count: " << ptr1.use_count() << std::endl; 
    //  外部输出 ptr1.use_count()，引用计数为1。
    //因为在 printShared中获得的 sharedPtr 是在其作用域结束后销毁的。
    // 在外部再次获取 shared_ptr
    std::shared_ptr<MyClass> ptr2 = ptr1->shared_from_this();
    //ptr2 被创建，引用计数增加为2。
    std::cout << "External use count after second shared_ptr creation: " << ptr1.use_count() << std::endl;  //  2

    ptr1->printShared();  //再次获取了 std::shared_ptr，引用计数增加为3。 
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
    //this 指针是裸指针，这样做将会导致两个独立的智能指针对象来管理同一个对象，可能会导致对象被重复析构
    //_register->set_login(std::shared_ptr<login>(this)); // 这也是错误的，会导致对象的二次析构
    _register->set_login(shared_from_this());
    // 正确的做法，返回一个当前类的智能指针,前提是已经有一个智能指针对它做了管理
}

int main() {
    std::shared_ptr<login> loginPtr = std::make_shared<login>();
    loginPtr->initSignals();

    return 0;
}
