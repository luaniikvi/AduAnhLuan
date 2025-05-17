#include<iostream>
using namespace std;
int main(){
    int a[3];
    cin>>a[0] >> a[1] >> a[2];
    int min=a[0];int max =a[0];
    for(int i = 1; i<3;i++){
        if(a[i] > max) max = a[i];
        if(a[i] < min) min = a[i];
    }
    cout << min << " " << max;

    return 0;
}