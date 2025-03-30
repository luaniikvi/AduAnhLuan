#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int m , n ;
    cin >> m >> n;

    vector<int> a (m);

    for(int &city : a)
    {
        for(int i=0 ; i < n ; i++)
        {
            int a;cin >> a;
            city+=a;
        }
    }

    for(int i=0 ; i < m-1 ; i++)
    {
        for(int j = i+1 ; j < m ; j++)
        {
            if(a[i] >= a[j] || (a[i] == a[j] && i >= j))
                swap(a[i],a[j]);
        }
    }

    int k;cin >> k;
    cout << n - a[k-1];
    return 0;
}