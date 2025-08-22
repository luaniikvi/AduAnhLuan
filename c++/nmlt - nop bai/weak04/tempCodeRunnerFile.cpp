#include <iostream>
#define ll long long
using namespace std;


int main(){
    int n,a;
    cin >> n;
    int dem =0;
    ll tich =1;
    for(int i =0 ; i <n ; i++){
        cin >> a;
        if(a==0) continue;
        tich*=a;
    }

    while(tich%10==0){
        if(tich == 0) break;
        tich /= 10;
        dem ++;
    }
    
    cout << dem;

    return 0;
}