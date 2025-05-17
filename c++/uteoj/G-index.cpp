#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[10000];
    long long sum = 0;
    for(int i= 0 ; i< n ; i++)
    {
        cin >> a[i];
    }
    for(int i= 0 ; i< n ; i++)
    {
        sum+=a[i];
        if(sum < pow(i+1,2))
        {
            cout << i;
            return 0;
        }
    }
    cout << n;
}