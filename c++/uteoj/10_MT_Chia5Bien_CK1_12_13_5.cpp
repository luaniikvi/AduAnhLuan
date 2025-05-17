#include<iostream>
#define ll long long
using namespace std;
int main(){
    int m,n;
    cin >> m >> n; // kick thuoc;
    ll a[100][100];
    ll sum =0;
    int count = 0;

    for(int i =0; i < m ; i++){
        for(int j =0; j < n ; j++){
            cin >> a[i][j];
            if(i == 0 || i == m-1 || j == 0 || j == n-1){
                if(a[i][j]%5 == 0)
                {
                    sum+=a[i][j];count++;
                }
            }
        }
    }

    if(count == 0) cout << 0;
    else cout << sum/count;
}

