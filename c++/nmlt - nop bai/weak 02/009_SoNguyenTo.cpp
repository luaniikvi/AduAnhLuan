#include<iostream>
#include<math.h>
#define ll long long

bool isElementNum(ll n);

int main(){
    ll n;
    std::cin >> n;
    std::cout << ((isElementNum(n)) ? "YES" : "NO");

    return 0;
}
bool isElementNum(ll n){
    if(n==2) return true;
    for(ll i=2 ; i<=sqrt(n) ; i++){
        if(n%i==0) return false;
    }

    return true;
}