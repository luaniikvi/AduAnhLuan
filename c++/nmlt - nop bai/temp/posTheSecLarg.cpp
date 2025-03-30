#include<iostream>
#include<climits>
using namespace std;

void find(int a[] , int size);

int main(){
    int n;
    cin >> n;
    int a[n];
    //
    for(int i=0; i<n ;i++){
        cin >> a[i];
    }
    //
    find(a , n);

    return 0;
}

void find(int a[] , int size){
    // int size = sizeof(a[]) / sizeof(a[0]);
    // largest
    int largest = INT_MIN;;
    for(int i= 0 ; i<size ; i++){
        if(a[i] > largest){
            largest = a[i];
        }
        else continue;
    }
    //sec
    int sec= INT_MIN;
    for(int i= 0 ; i<size ; i++){
        if(a[i] == largest) continue;
        if(a[i] > sec) sec = a[i];
        else continue;
    }
    //cout sec
    for(int i= 0 ; i<size ; i++){
        if(a[i] == sec){
            cout << "Pos: " << i;
            return;
        }
    }
}