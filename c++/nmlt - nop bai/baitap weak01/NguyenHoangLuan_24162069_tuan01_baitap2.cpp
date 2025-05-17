#include<iostream>
#include<iomanip> //fixed
using namespace std;
//     Tinh tong trung binh 3 so nguyen

float tbc(int a, int b, int c);

int main(){

    int a,b,c;
    cin >> a >> b >> c; // nhap 3 so nguyen

    cout << fixed << setprecision(2); // lam tron
    cout << tbc(a,b,c);

    return 0;
}

float tbc(int a, int b, int c){
    return (float)(a+b+c)/3;
}