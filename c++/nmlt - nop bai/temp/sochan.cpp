#include <iostream>
#include<math.h>
using namespace std;

void check (unsigned long long n );


int main(){
    unsigned long long n;
    cin >> n;
    check(n);
    
}
void check (unsigned long long n){
    for(int i=2; i<= sqrt(n); i++){
        if(n%i == 0){
            cout << "NO";
            return;
        }
    }
    cout << "YES";
    return;
}
