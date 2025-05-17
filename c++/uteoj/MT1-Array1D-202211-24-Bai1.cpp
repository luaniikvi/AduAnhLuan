#include<iostream>
#include<cmath>
using namespace std;
int main(){

    int size;cin >> size;
    int arr[100];

    for(int i=0;i<size;i++){
        cin >> arr[i];
    }
    int _min = 1e6;
    for(int i=1 ; i<size ;i++)
    {
        _min = min(_min , abs(arr[i]-arr[i-1]));
    }
    cout << _min;
    return 0;
}