#include<iostream>
#include<math.h>
using namespace std;

long long tinhTienTaxi(double kilometers){
    long long money =12500;
    if(kilometers <= 0.7) return money;
    kilometers = ceil(kilometers-0.7);
    if(kilometers <= 30){
        money+= kilometers*17000;
    }
    else{
        money+= 30* 17000 + (kilometers-30)*14000;
    }
    return money;
}

int main(){
    double kilometers;
    cin >> kilometers;

    cout << tinhTienTaxi(kilometers);

    return 0;
}