#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &i : a) cin >> i;

    sort(a.begin(),a.end());

    for(int &i : a) cout << i << " ";

    return 0;
}