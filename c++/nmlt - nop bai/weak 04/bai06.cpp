#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    a.push_back(x);
    sort(a.begin(),a.end());
    cout << a[(int)((n+1)/2)];
    return 0;
}