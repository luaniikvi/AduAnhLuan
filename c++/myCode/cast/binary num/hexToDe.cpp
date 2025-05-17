#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n;cin >> n;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    
    sort(a.begin(),a.end());

    cout << a[1];
    return 0;
}