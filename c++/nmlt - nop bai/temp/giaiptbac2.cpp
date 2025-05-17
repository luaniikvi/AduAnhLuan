#include<iostream>
#include<math.h>
using namespace std;

void giai(double a, double b, double c);
double delta(double a, double b, double c);

int main(){
    double a,b,c;
    cout << "Nhap a,b,c: ";
    cin >> a >> b >>c;
    giai(a,b,c);

    return 0;
}
void giai(double a, double b, double c){
    double del = delta(a,b,c);
    if(del == 0){
        cout << "pt co nghiem kep x = " << (-b / (2*a));
    }
    else if(del > 0){
        cout << "pt co 2 nghiem thuc" << endl;
        cout << "x1 = " << (-b + sqrt(del) / (2*a)) << endl;
        cout << "x2 = " << (-b - sqrt(del) / (2*a)) << endl;
    }
    else cout << "pt vo nghiem";

    return;
}
double delta(double a, double b, double c){
    return b*b - 4*a*c;
}