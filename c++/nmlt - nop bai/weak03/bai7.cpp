#include<bits/stdc++.h>
using namespace std;

//int sizeNum(int num);
int dupeNum(int num);


int main(){
    int n;
    cin >> n;
    long long sum =0;
    for(int i=1;i <= n; i++){
        sum+= dupeNum(i);
    }
    cout << sum;

    return 0;
}


int sizeNum(int num){
    if (num == 0) return 1;
    int sizeN =0;
    while(num!=0){
        num /= 10;
        sizeN++;
    }
    return sizeN;
}

int mu10(int mu){
    if(mu == 0) return 1; 
    return 10*mu10(mu-1);
}

int dupeNum(int num){
    int temp = num *mu10(sizeNum(num));
    return (temp + num);
}