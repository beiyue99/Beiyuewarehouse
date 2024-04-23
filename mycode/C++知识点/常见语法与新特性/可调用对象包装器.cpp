



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

	// ʹ�� std::function ָ�� Calculator �ĳ�Ա����
	handleFunc func1 = std::bind(&Calculator::add, &calc, std::placeholders::_1, std::placeholders::_2);
	handleFunc func2 = std::bind(&Calculator::subtract, &calc, std::placeholders::_1, std::placeholders::_2);
	// ʹ�� std::function ָ��ȫ�ֺ���
	handleFunc func3 = multiply;

	// ʹ�ú���ָ�����
	int result1 = func1(5, 3); // ���� Calculator::add
	int result2 = func2(5, 3); // ���� Calculator::subtract
	int result3 = func3(5, 3); // ����ȫ�ֺ��� multiply



	// ʹ��ԭ������ָ��ָ�� Calculator �ĳ�Ա�����ǲ����е�
	// ��Ϊ��Ա����ָ�����ͨ����ָ�����Ͳ�һ��������ֱ�Ӹ�ֵ
	// ʹ��ԭ������ָ��ָ��ȫ�ֺ���
	//handleFunc func1 = multiply;
	// ʹ�ú���ָ�����
	//int result = func1(5, 3); // ����ȫ�ֺ��� multiply

	return 0;
}



