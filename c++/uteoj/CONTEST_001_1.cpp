#include<iostream>
using namespace std;
long long C(int n,int k)
{
    long long int tu=1;
    int dev = 1;
    for(int i = k+1; i<=n ; i++)
    {
        tu*=i;
        tu/=dev++;
    }
    for(int i=dev ; i<= n-k ; i++)
    {
        tu/=i;
    }
    return tu;
}
int main()
{
    int n,k;
    cin >> n >> k;

    cout << C(n,k);
}   