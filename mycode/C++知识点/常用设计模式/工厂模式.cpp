



// 抽象产品类 - Shape  
class Shape {
public:
    virtual void draw() const = 0;
    virtual ~Shape() {}
};

// 具体产品类 - Circle  
class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a Circle" << std::endl;
    }
};

// 具体产品类 - Rectangle  
class Rectangle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a Rectangle" << std::endl;
    }
};

// 工厂类 - ShapeFactory  
class ShapeFactory {
private:
    // 禁止实例化  
    ShapeFactory() = delete;

    static std::unordered_map<std::string, std::function<std::unique_ptr<Shape>()>> shapeCreators;
    //保存了形状类型，和一个可调用对象（形状创建函数），该对象返回形状指针

public:
    // 注册形状创建函数  
    static void registerShape(const std::string& shapeType, std::function<std::unique_ptr<Shape>()> creator) {
        shapeCreators[shapeType] = creator;
    }

    // 创建形状对象  
    static std::unique_ptr<Shape> createShape(const std::string& shapeType) {
        auto it = shapeCreators.find(shapeType);   //如果发现形状存在，通过可调用对象返回形状指针
        if (it != shapeCreators.end()) {
            return it->second();
        }
        return nullptr;
    }
};

// 初始化 shapeCreators 静态成员变量  
std::unordered_map<std::string, std::function<std::unique_ptr<Shape>()>> ShapeFactory::shapeCreators;

// 注册形状创建函数  
void registerShapes() {
    ShapeFactory::registerShape("Circle", []() { return std::make_unique<Circle>(); });
    ShapeFactory::registerShape("Rectangle", []() { return std::make_unique<Rectangle>(); });
}

int main() {
    // 注册形状  
    registerShapes();

    // 创建并绘制形状  
    std::unique_ptr<Shape> shape;
    shape = ShapeFactory::createShape("Circle");
    if (shape) {
        shape->draw();
    }

    shape = ShapeFactory::createShape("Rectangle");
    if (shape) {
        shape->draw();
    }

    // 尝试创建未注册的形状  
    shape = ShapeFactory::createShape("Triangle");
    if (!shape) {
        std::cout << "Shape 'Triangle' is not registered." << std::endl;
    }

    return 0;
}