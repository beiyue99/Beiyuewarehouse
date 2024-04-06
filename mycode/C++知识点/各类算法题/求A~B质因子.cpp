#include <iostream>
#include <vector>

using namespace std;

// 计算质因子的函数
vector<int> primeFactors(int n) {
    vector<int> factors;
    // 输出能够整除n的2的个数
    while (n % 2 == 0) {
        factors.push_back(2);
        n = n / 2;
    }
    // n此时必然是奇数。因此我们可以跳过一个元素（i = i + 2）
    for (int i = 3; i * i <= n; i = i + 2) {
        // 当i整除n时，输出i并将n除以i
        while (n % i == 0) {
            factors.push_back(i);
            n = n / i;
        }
    }
    // 当n是大于2的质数时，处理这种情况
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
