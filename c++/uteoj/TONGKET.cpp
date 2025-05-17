#include<iostream>
#include<cmath>
using namespace std;


int main()
{
    int khoa;
    cin >> khoa;

    double diemDau = (khoa >= 21 ? 4 : 5 );

    double d1,d2;
    cin >> d1 >> d2;
    double dtb = (d1+d2)/2;
    dtb = round(dtb*10)/10;

    cout << (dtb >= diemDau ? "Pass" : "Fail");

    return 0;
}