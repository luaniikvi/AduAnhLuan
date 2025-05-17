#include<iostream>
#include<math.h>
using namespace std;

void tinhTienTaxi(double kilometers){
    long long money =0;
    if(kilometers <= 0.7){
        money += 12500;
    }
    else{
        kilometers = ceil(kilometers - 0.7);
        money += 12500;
        if(kilometers < 30){
            money += kilometers*17000;
        }
        else{
            kilometers -= 30;
            money += 30*17000;
            money += kilometers*14000;
        }
    }
    cout << money;
    return;
}

int main(){
    double kilometers;
    //cout << "Nhap quang duong: ";
    cin >> kilometers;

    tinhTienTaxi(kilometers);

    return 0;
}