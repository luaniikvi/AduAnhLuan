#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Nhap n: ";
    cin >> n;
    int count =0;
    while(n!=0){
        cout << n << endl;
        n/=10;
        count++;
    }
    cout << "n co " << count << " chu so";

    return 0;
}