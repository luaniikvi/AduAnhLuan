#include<iostream>
using namespace std;

//       hoan doi gia tri 2 bien

int main(){
    // e dùng thuật toán kh cần biến temp
    int a,b;
    cin >> a >> b;
    
    a+=b;
    b = a-b;
    a = a-b;
    cout << a << " " << b;

    return 0;
}