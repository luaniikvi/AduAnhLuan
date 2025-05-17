#include<bits/stdc++.h>
using namespace std;
set<long> arr;
int main()
{
    int m,n; cin >> m >> n;
    for(int input, i=0 ; i<m+n; i++){
        cin >> input;arr.insert(input);
    }
    for(auto i : arr) cout << i << ' ';
    return 0;
}