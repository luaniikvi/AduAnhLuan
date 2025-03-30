#include<bits/stdc++.h>
using namespace std;

bool checkNhon(double a, double b,double c);
bool checkTu(double a, double b,double c);
bool checkVuong(double a, double b,double c);

int main(){
    double a,b;
    cin >> a >> b;
    double c =180 -a -b;
    //cout <<"c: " << c;
    if(checkVuong(a,b,c)){
        if(a==b || b == c || c == a){
            cout << 0;
        }
        else cout << 1;
    }
    else if(checkTu(a,b,c)) cout << 2;
    else if(checkNhon(a,b,c)) cout << 3;

    return 0;
}
bool checkNhon(double a, double b,double c){
    return (a <90.0 && b< 90.0 && c <90.0);
}

bool checkTu(double a, double b,double c){
    cout << "yes" << endl;
    return (a > 90.0 || b > 90.0 || c > 90.0);
}
bool checkVuong(double a, double b,double c){
    return (a == 90.0 || b == 90.0 || c == 90.0);
}
