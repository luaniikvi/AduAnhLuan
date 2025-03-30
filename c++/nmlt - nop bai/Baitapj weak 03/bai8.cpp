#include<iostream>
using namespace std;

int main(){
    int a,b;
    cin >> a>> b;
    if(a > b) swap(a,b);

    if(a >= 10 && b <=20){
        cout << 0 << endl;
    }
    else if(a < 10 && b > 20){
        cout << 0 << endl;
    }
    else if(b<10 || a>20) cout<< 0;
    else cout << 1 << endl;
    
    return 0;
}