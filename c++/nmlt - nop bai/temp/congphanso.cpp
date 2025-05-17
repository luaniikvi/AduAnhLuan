#include<iostream>
using namespace std;

void inToiGian(long long a , long long b);
long long ucln(long long a, long long b);


int main(){

    int n;
    cin >> n;
    long long a[200];
    for (int i = 0 ; i<2*n ; i++){
        cin >> a[i];
    }

    long long tongTu=a[0];long long tongMau =a[1];

    for(int i = 1 ; i < n;i++){
        tongTu = tongTu*a[2*i +1] + tongMau*a[2*i];
        tongMau *= a[2*i +1];
    }
    inToiGian(tongTu , tongMau);
    return 0;
}

void inToiGian(long long a , long long b){
    long long uoc = ucln(a,b);
    cout << a/uoc << " " << b/uoc;

    return;
}

long long ucln(long long a, long long b){
    while(a!=b){
        if(a >b){
            a -=b;
        }
        else b-=a;
    }
    return a;
}
