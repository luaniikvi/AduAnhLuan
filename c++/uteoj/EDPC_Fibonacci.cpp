#include <iostream>
using namespace std;
const long long MOD = 1e9 + 7;

long long int fibonacci(long long n)
{
    if (n<=1) return n;
    else
    {
        long long int f0 = 0;
        long long int f1 = 1;
        for (long long i = 2; i <= n; i++)
        {
            long long int f2 = (f0 + f1) % MOD;
            f0 = f1;
            f1 = f2;
        }
        return f1;
    }
}

int main()
{
    long long n;
    cin >> n;
    cout << fibonacci(n) << endl;
    return 0;
}