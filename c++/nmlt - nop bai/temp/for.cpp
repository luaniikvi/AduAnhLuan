#include<iostream>

using namespace std;
int  main(){
    int n;
    do{
        cout << "Nhap n: ";
        cin >> n;
    }while(n<0);

    cout << "cac uoc cua n: " << endl;
    for(int i=1 ; i<=n ; i++){
        if(n%i == 0) cout << i << " ";
    }

    return 0;
}