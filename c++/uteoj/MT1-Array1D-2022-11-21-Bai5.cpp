#include<iostream>
using namespace std;
int main(){
    int n;cin>>n;
    int a[100];


    for(int i=0; i<n ; i++){
        cin>>a[i];
    }
    int sum=a[0];
    int max_sum=a[0];

    for(int i=1 ; i<n ; i++){
        sum = max(a[i] , sum +a[i]);
        max_sum = max(sum,max_sum);
    }
    cout << max_sum;
    return 0;
}