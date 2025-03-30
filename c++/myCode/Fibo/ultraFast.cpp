#include<iostream>
#include<vector>
using namespace std;

int slow_Fibo(int n);
unsigned long long fast_Fibo(int n);

int main()
{
    int n;
    cin >> n;
    //cout << slow_Fibo(n) << endl;
    cout << fast_Fibo(n) << endl;

    return 0;
}


int slow_Fibo(int n)
{
    if(n <= 1) return n;
    return slow_Fibo(n-1) + slow_Fibo(n-2);
}

unsigned long long int fast_Fibo(int n)
{
    if(n <= 1) return static_cast<long long>(n);
    if(n == 2) return static_cast<long long>(1);
    if(n == 3) return static_cast<long long>(2);
    vector<unsigned long long int> a;
    a.push_back(0);
    a.push_back(1);
    while(n > 1)
    {
        a.push_back(a.back() + a[a.size()-2]  );
        n--;
    }
    return a.back();
}

