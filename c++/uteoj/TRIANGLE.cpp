#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isTrangle(int a,int b,int c);
int main(){
    vector<int> d(3);
    cin >> d[0] >> d[1] >> d[2];
    sort(d.begin(),d.end());

    int time =0;
    if(isTrangle(d[0],d[1],d[2])){
        cout << time;
    }
    else{
        while(!isTrangle(d[0],d[1],d[2])){
            d[2]--;
            time++;
        }
        cout << time;
    }

    return 0;
}

bool isTrangle(int a,int b,int c){
    return(a+b>c && a+c>b && c+b>a);
}