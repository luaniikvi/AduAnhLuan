#include<iostream>
#include<math.h>
using namespace std;
void lm(float a , float b);

int main(){
    int a,b;

    cin >> a>>b;
    lm(a,b);
    return 0;
}
void lm(float a , float b){
    //cout << a/b << endl;
    cout << ceil((float)(a/b));
    return;
}