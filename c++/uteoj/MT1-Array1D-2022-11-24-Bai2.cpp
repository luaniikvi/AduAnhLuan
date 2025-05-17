#include<iostream>
#define ll long long
using namespace std;
int main()
{
    int size;
    cin >> size;
    ll arr[100];
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