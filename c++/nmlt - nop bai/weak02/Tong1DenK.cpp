#include<iostream>
using namespace std;

long long tongK(long long n){
    if(n == 0) return 0;
    long long sum = ((1+n)*n)/2;
    return sum;
}

int main(){
    long long n;
    cin >> n;
    int i =0;
    while(tongK(i+1) < n){
        i++;
    }
    cout << i;
    return 0;
}