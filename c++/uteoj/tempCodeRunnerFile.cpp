#include<iostream>
#include<vector>
using namespace std;

int n,sum;
vector<int> a;

int main()
{
    cin >> n;
    a.resize(n+1);
    for(int i=1 ; i<=n ; i++)
        cin >> a[i]; 
    for(int i=2 ; i<= n ; i++)
    {
        sum = max(sum , a[i] - a[i-1]);
    }
    cout << sum;
    return 0;
}
