#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[1000],b[1000];

    for(int i = 0 ; i<n ; i++){
        cin >> a[i];
    }
    for(int i = 0 ; i<n ; i++){
        cin >> b[i];
    }

    int SoBanh = INT_MAX;

    for(int i = 0 ; i<n ; i++){
        if(b[i]/a[i] < SoBanh) SoBanh = b[i] / a[i];
    }

    cout << SoBanh;
    return 0;
}