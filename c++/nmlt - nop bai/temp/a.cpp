#include<iostream>
using namespace std;

bool isNhuan(int year);
void checkNgay(int thang, int nam);


int main(){
    int nam;
    cout << "nhap nam: "; cin >> nam;
    int thang;
    cout << "nhap thang: "; cin >> thang;
    checkNgay(thang, nam);

    return 0;
}
bool isNhuan(int year){
    if(year % 400 == 0 || (year % 4 == 0 && year %100 != 0)) return true;
    else return false;
}
void checkNgay(int thang , int nam){
    if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12){
        cout << "31 ngay";
    }
    else if (thang == 4 || thang == 6 || thang == 9 || thang == 11 ){
        cout << "30 ngay";
    }
    else if(isNhuan(nam)){
        cout << "29 ngay";
    }
    else cout << "28 ngay";
}
