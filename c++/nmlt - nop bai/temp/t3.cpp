#include<iostream>
using namespace std;

void func(float x,int a,int b ,int c,int d);

int main(){
    float x;
    int a,b,c,d;
    cin >>x>>a>>b>>c>>d;
    func(x,a,b,c,d);

    return 0;
}
void func(float x,int a,int b ,int c,int d){
    int price;
    int sum =0;
    while(x!=0){
        if( x >= 0 && x <=50){
            price =a;
        }

        if( x >= 51 && x <=100){
            price =b;
        }

        if( x >= 101 && x <=150){
            price = c;
        }

        if( x >= 151){
            price = d;
        }
        x--;
        sum+= price;
        // cout << "p= " << price << endl;
        // cout << "x = " << x << endl;
        // cout << "s = " << sum << endl;

    }
    cout << sum;
    return;
}
