#include<iostream>
using namespace std;

int main(){

    double dtb;
    cout << "Nhap dtb: "; cin >> dtb;

    if(dtb >= 9){
        cout << "Gioi";
    }
    else if(dtb >= 7){
        cout << "Kha";
    }
    else if(dtb >= 5){
        cout << "Trung binh";
    }
    else cout << "Hoc lai";

    return 0;
}