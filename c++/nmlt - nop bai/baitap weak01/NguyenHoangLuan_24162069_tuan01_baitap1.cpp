#include<iostream>
using namespace std;

int main(){
    int donGia;
    int soLuong;
    const float thue = 0.1; //  thue = 10% | thuế cao quá.

    cout << "Nhap don gia: " ;cin >> donGia;
    cout << "Nhap soluong: " ;cin >> soLuong;

    cout << "    Tong tien truoc thue: " << donGia << "*" << soLuong << "=" << donGia*soLuong << endl;
    cout << "               Tien thue: " << donGia*soLuong*thue << endl;
    cout << "      Tong tien sau thue: " << donGia*soLuong*(1+thue);

    return 0;
}