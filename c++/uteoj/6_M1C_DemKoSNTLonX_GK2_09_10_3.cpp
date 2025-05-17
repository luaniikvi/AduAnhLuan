#include<iostream>
using namespace std;
bool isPrime(int n)
{
    if(n<=1) return false;
    if(n<=3) return true;
    if(n%2==0 || n%3==0) return false;
    for(int i=5 ; i*i<=n ; i+=6){
        if(n%i == 0 || n) return false;
    }

    return true;
}

int main()
{
    int n,x;
    cin >> n >> x;
    int a;
    int count =0;
    for(int i =0 ; i< n ; i++)
    {
        cin >> a;
        if(!isPrime(a) && a > x) count++;
    }

    cout << count;

    return 0;
}
