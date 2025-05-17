#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int n,a[100];
    cin >> n;
    for(int i=0 ;i<n; i++) cin >> a[i];

    long long _max = INT_MIN;
    for(int i=0 ; i<n-1 ; i++)
    {
        for(int j= i+1 ;j<n ; j++)
        {
            if(a[i] == a[j]) continue;
            _max = max(_max , 1LL*a[i]*a[j]);
        }
    }
    cout << (_max == INT_MIN ? 0 : _max);
}