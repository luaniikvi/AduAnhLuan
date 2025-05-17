#include<iostream>
using namespace std;

int main(){
    int n,k,a[100],b[100];
    cin >> n >> k;

    for(int i = 0 ; i<n ;i++) cin >> a[i];

    if(a[0] != a[n-1]) cout << -1;
    else
    {
        for(int i=k ; i<k+n ; i++)
        {
            if(i >= n) cout << a[i-(n-1)] << " ";
            else cout << a[i] << " ";
        }
    }

    return 0;
}