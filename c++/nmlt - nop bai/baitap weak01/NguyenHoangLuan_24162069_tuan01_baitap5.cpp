#include<iostream>
#include<math.h>
#include<iomanip> // fixed
using namespace std;
//            Tinh nghiem pt bac2
void giaiNghiem(float a, float b, float c);

int main(){
    float a,b,c;

    cout << "Nhap a: " ; cin >> a;
    cout << "Nhap b: " ; cin >> b;
    cout << "Nhap c: " ; cin >> c;

    giaiNghiem(a,b,c);

    return 0;
}

void giaiNghiem(float a, float b, float c){
    float delta= b*b - 4*a*c;
    cout << fixed << setprecision(2);
    //  Vì đề kh cho điều kiện input nên có 2 trường hợp
    // delta >= 0  -> số thực
    if(delta >=0){
        // cout << fixed << setprecision(2);
        cout << (-b + sqrt(delta))/(2*a);
        return;
    }
    // delta < 0 -> số phức
    else{
        cout << (-b)/(2*a) << " + " << sqrt(-delta)/(2*a) << "i";
        return;
    }

    return;
}
