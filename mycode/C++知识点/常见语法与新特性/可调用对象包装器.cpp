



class Calculator {
public:
	int add(int a, int b) {
		return a + b;
	}

	int subtract(int a, int b) {
		return a - b;
	}
};

int multiply(int a, int b) {
	return a * b;
}

using handleFunc = std::function<int(int, int)>;
//typedef int(*handleFunc)(int, int);


int main() {
	Calculator calc;

	// 使用 std::function 指向 Calculator 的成员函数
	handleFunc func1 = std::bind(&Calculator::add, &calc, std::placeholders::_1, std::placeholders::_2);
	handleFunc func2 = std::bind(&Calculator::subtract, &calc, std::placeholders::_1, std::placeholders::_2);
	// 使用 std::function 指向全局函数
	handleFunc func3 = multiply;

	// 使用函数指针调用
	int result1 = func1(5, 3); // 调用 Calculator::add
	int result2 = func2(5, 3); // 调用 Calculator::subtract
	int result3 = func3(5, 3); // 调用全局函数 multiply



	// 使用原生函数指针指向 Calculator 的成员函数是不可行的
	// 因为成员函数指针和普通函数指针类型不一样，不能直接赋值
	// 使用原生函数指针指向全局函数
	//handleFunc func1 = multiply;
	// 使用函数指针调用
	//int result = func1(5, 3); // 调用全局函数 multiply

	return 0;
}



