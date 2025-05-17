#include<iostream>
#include<vector>
#define ll long long
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int size;
    cin >> size;
    vector<ll> arr(size);
    ll sum = 0;
    for(int i=0; i<size ;i++){
        cin >> arr[i];
        sum+= arr[i];
    }

    int pos = -1;
    ll tong_phu =0;

    for(int vachNgan = 0 ; vachNgan<size-1 ; vachNgan ++){
        for(int i=0 ; i<=vachNgan ; i++){
            tong_phu+=arr[i];
        }
        if(tong_phu == sum - tong_phu){
            pos = vachNgan;
            break;
        }
        tong_phu =0;
    }

    cout << pos;


    return 0;
}