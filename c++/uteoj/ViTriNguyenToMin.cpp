#include<iostream>
#include<climits>
using namespace std;

int _pos_MinPrime(int a[],int size);

int main()
{
    int a[100];
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }

    cout << _pos_MinPrime(a , n);


    return 0;
}

bool isPrime(int n)
{
    if(n <= 1) return false;
    if(n<= 3) return true;
    if( n%2 == 0 || n % 3 == 0 ) return false;
    for(int i=5 ; i*i <= n ; i+=6)
    {
        if(n%i == 0 || n%(i+2) == 0) return false;
    }
    return true;
}

int _min(int a, int b)
{
    return ( a < b ? a : b);
}

int _pos_MinPrime(int a[],int size)
{   
    int min = INT_MAX;
    for(int i=0;i<size;i++)
    {
        if(isPrime(a[i]))
        {
            min = _min(min,a[i]);
        }
    }
    if( min == INT_MAX) return -1;
    else 
    {
        for(int i=0 ; i<size ; i++)
        {
            if(a[i] == min) return i;
        }
    }
}