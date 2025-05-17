#include <iostream>
#include <vector>
#include <cmath>
bool isPrime(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i <= std::sqrt(n); ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}

// Hàm đếm số cách phân tích
int countPrimePairs(int n) {
    int count = 0;
    std::vector<int> primes;
    
    // Tìm các số nguyên tố nhỏ hơn n
    for (int i = 2; i < n; ++i) {
        if (isPrime(i))
            primes.push_back(i);
    }
    
    // Đếm số cặp nguyên tố có tổng bằng n
    for (size_t i = 0; i < primes.size(); ++i) {
        if (primes[i] <= n - primes[i] && isPrime(n - primes[i])) {
            ++count;
        }
    }
    
    return count;
}

int main() {
    int n = 34;
    std::cin >> n; // Thay số này bằng số bạn muốn phân tích
    std::cout << countPrimePairs(n) << std::endl;
    return 0;
}
