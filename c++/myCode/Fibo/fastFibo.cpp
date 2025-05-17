#include<iostream>
using namespace std;

int main()
{
    unsigned long long F[51];
    F[0] = 0;F[1] = 1;
    int n;
    cin >> n;

    int i = 2;
    while(true)
    {
        F[i] = F[i-1] + F[i-2];
        if(i == n) break;
        i++;
    }
    cout << F[n];
}