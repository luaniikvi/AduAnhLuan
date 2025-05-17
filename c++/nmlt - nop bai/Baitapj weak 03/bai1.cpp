#include<bits/stdc++.h>
using namespace std;
int main(){

    double dem1,dem2,dtb;
    cin >> dem1 >> dem2;
    dtb = (dem1+dem2)*0.5;
    
    string xepLoai ="";

    if(dtb>=8){
        if(dem1 < 7 || dem2 < 7) xepLoai = "kha";
        else xepLoai = "gioi";
    }
    else if(dtb >= 6.5){
        if(dem1 < 6 || dem2 < 6) xepLoai = "tb";
        else xepLoai = "kha";
    }
    else if(dtb >= 5){
        xepLoai = "tb";
    }
    else xepLoai = "rot";

    if(xepLoai == "gioi") cout << 1;
    else if(xepLoai == "kha") cout << 2;
    else if(xepLoai == "tb" ) cout << 3;
    else if(xepLoai == "rot") cout << 940000;

    return 0;
}
