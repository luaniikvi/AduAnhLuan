#include<iostream>
using namespace std;

long long giaiThua(int n){
    if(n == 0 || n ==1) return 1;
    return (1LL*n*giaiThua(n-1));
}

int main(){
    int n;
    do{
        cout << "nhap n: ";
        cin >> n;
    }while(n<0);

    cout << "Giai thua cua n la "<<giaiThua(n);

    return 0;
}