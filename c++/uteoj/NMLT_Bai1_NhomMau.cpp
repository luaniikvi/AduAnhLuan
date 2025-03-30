#include<bits/stdc++.h> 
#include<cmath>
using namespace std;

int mylog2(int n);

int main(){
    int toHop[4][4] = {
    {9 ,15,7 ,9 },
    {15,10,7 ,10},
    {7 ,7 ,7 ,3 },
    {9 ,10,3 ,8 }
    };

    int mauBo,mauMe;
    cin >> mauMe;
    cin >> mauBo;
    int i =mylog2(mauBo);
    int j = mylog2(mauMe);
    cout << toHop[i][j];

    return 0;
}
int mylog2(int n){
    return ceil(log(n)/log(2));
}
