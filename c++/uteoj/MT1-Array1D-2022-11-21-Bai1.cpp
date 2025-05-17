#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[100];
    int fpos = -1, epos = -1;
    for(int i=0 ; i<n ; i++) cin >> a[i];
    int _max = a[0];
    for(int i=1 ; i<n ; i++) _max = max(_max,a[i]);
    for(int i=0 ; i<n ; i++)
    {
        if(a[i] == _max){ fpos = i ; break;}
    }
    for(int i=0 ; i<n ; i++)
    {
        if(a[i] == _max) epos = i;
    }
    cout << (epos - fpos);
}