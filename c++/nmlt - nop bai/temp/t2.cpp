#include<iostream>
using namespace std;

void check(int a[]);

int main(){
    int a[3];
    for(int i =0 ; i<3 ;i++){
        cin >> a[i];
    }

    check(a);

    return 0;
}

void check(int a[]){
    if(a[2] == a[0]){
        cout << a[1];
        return;
    }

    if(a[2] == a[1]){
        cout << a[0];
        return;
    }

}