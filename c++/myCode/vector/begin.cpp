#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v1 = {1,2,3,4,5};
    v1.insert(v1.end()-1, 90);

    for(int i: v1){
        cout << i << " " ;
    }
    cout << endl;


    return 0;
}