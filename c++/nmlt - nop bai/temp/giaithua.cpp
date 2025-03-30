#include<iostream>
using namespace std;

long long giaiThua(int n);

int main(){
    int n;
    cin >> n;
    cout << giaiThua(n);

    return 0;
}

long long giaiThua(int n){
    if(n == 0) return 1;
    return (1LL * n * giaiThua(n-1)); 
}
