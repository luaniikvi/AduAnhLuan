#include<iostream>
using namespace std;


void fu(int a, int b, int c, int d);

int main(){
    int a,b,c,d;
    cin >>a >> b>> c>>d;
    fu(a,b,c,d);

    return 0;
}

void fu(int a, int b, int c, int d){
    
    if( c <= b && c >=a){
        cout << "YES";
        return;
    }
    if(d <= b && d >=a){
        cout << "YES";
        return;
    }
    if( c<=a && d>=b){
        cout << "YES";
        return;
    }
    if( d<=a && c>=b){
        cout << "YES";
        return;
    }
    cout << "NO";
    return;
}
