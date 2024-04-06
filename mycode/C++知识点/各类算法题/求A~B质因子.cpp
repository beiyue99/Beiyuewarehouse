#include <iostream>
#include <vector>

using namespace std;

// ���������ӵĺ���
vector<int> primeFactors(int n) {
    vector<int> factors;
    // ����ܹ�����n��2�ĸ���
    while (n % 2 == 0) {
        factors.push_back(2);
        n = n / 2;
    }
    // n��ʱ��Ȼ��������������ǿ�������һ��Ԫ�أ�i = i + 2��
    for (int i = 3; i * i <= n; i = i + 2) {
        // ��i����nʱ�����i����n����i
        while (n % i == 0) {
            factors.push_back(i);
            n = n / i;
        }
    }
    // ��n�Ǵ���2������ʱ�������������
    if (n > 2)
        factors.push_back(n);
    return factors;
}

int main() {
    int A, B;
    cin >> A >> B;

    for (int i = A; i <= B; ++i) {
        vector<int> factors = primeFactors(i);
        for (size_t j = 0; j < factors.size(); ++j) {
            cout << factors[j] << " ";
        }
        cout << endl;
    }

    return 0;
}
