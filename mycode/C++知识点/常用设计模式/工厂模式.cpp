



// �����Ʒ�� - Shape  
class Shape {
public:
    virtual void draw() const = 0;
    virtual ~Shape() {}
};

// �����Ʒ�� - Circle  
class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a Circle" << std::endl;
    }
};

// �����Ʒ�� - Rectangle  
class Rectangle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a Rectangle" << std::endl;
    }
};

// ������ - ShapeFactory  
class ShapeFactory {
private:
    // ��ֹʵ����  
    ShapeFactory() = delete;


    static std::unordered_map<std::string, std::function<std::unique_ptr<Shape>()>> shapeCreators;
    //��������״���ͣ���һ���ɵ��ö�����״�������������ö��󷵻���״ָ��

public:
    // ע����״��������  
    static void registerShape(const std::string& shapeType, std::function<std::unique_ptr<Shape>()> creator) {
        shapeCreators[shapeType] = creator;
    }

    // ������״����  
    static std::unique_ptr<Shape> createShape(const std::string& shapeType) {
        auto it = shapeCreators.find(shapeType);   //���������״���ڣ�ͨ���ɵ��ö��󷵻���״ָ��
        if (it != shapeCreators.end()) {
            return it->second();
        }
        return nullptr;
    }
};

// ��ʼ�� shapeCreators ��̬��Ա����  
std::unordered_map<std::string, std::function<std::unique_ptr<Shape>()>> ShapeFactory::shapeCreators;

// ע����״��������  
void registerShapes() {
    ShapeFactory::registerShape("Circle", []() { return std::make_unique<Circle>(); });
    ShapeFactory::registerShape("Rectangle", []() { return std::make_unique<Rectangle>(); });
}

int main() {
    // ע����״  
    registerShapes();

    // ������������״  
    std::unique_ptr<Shape> shape;
    shape = ShapeFactory::createShape("Circle");
    if (shape) {
        shape->draw();
    }

    shape = ShapeFactory::createShape("Rectangle");
    if (shape) {
        shape->draw();
    }

    // ���Դ���δע�����״  
    shape = ShapeFactory::createShape("Triangle");
    if (!shape) {
        std::cout << "Shape 'Triangle' is not registered." << std::endl;
    }

    return 0;
}