#include <iostream>
#include <vector>
#include <immintrin.h>
typedef __m256i uint64;
using namespace std;
struct SignedFoo { 
  long long var : 64; 
}; 
 
struct UnsinedFoo { 
  unsigned long long var : 64; 
};


// Function to multiply two matrices
vector<vector<long long int>> multiply(const vector<vector<long long int>>& a, const vector<vector<long long int>>& b) {
    vector<vector<long long int>> result(2, vector<long long int>(2));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < 2; ++k) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return result;
}

// Function to perform matrix exponentiation
vector<vector<long long int>> matrixPower(vector<vector<long long int>> base, int exp) {
    vector<vector<long long int>> result = {{1, 0}, {0, 1}}; // Identity matrix
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = multiply(result, base);
        }
        base = multiply(base, base);
        exp /= 2;
    }
    return result;
}

// Function to calculate the nth Fibonacci number
long long int fibonacci(int n) {
    if (n == 0) return 0;
    vector<vector<long long int>> base = {{1, 1}, {1, 0}};
    vector<vector<long long int>> result = matrixPower(base, n - 1);
    return result[0][0];
}

int main() {
    int n;
    //cout << "Enter the Fibonacci number to calculate: ";
    cin >> n;
    //cout << "Fibonacci number " << n << " is " << fibonacci(n) << endl;
    cout << fibonacci(n);
    return 0;
}