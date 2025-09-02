#include <iostream>
#include <algorithm>

using namespace std;

void in(int a[], int size){
    for(int i= 0 ; i<size ; i++)
    {
        cin >> a[i];
    }
}

main(){
    int size = 4;
    int temp[size];
    in(temp,size);
    for(int i=0 ; i< size ; i++) cout << temp[i] << " ";
}