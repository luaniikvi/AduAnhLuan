#include<iostream>
using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c;

    int n[3]= {a,b,c};
    int max = n[0];
    int min = n[0];

    for (int i=1 ; i<3 ;++i){
        if(n[i] < min){
            min = n[i];
        }
        if(n[i]>max){
            max = n[i];
        }
    }
    cout << min << " " << max ;

    return 0;
}