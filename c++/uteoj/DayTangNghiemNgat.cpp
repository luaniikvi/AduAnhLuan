#include<iostream>
#include<vector>
using namespace std;

void kiemTra(vector<int> a);
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i =0; i<n;i++){
        cin >> a[i];
    }
    kiemTra(a);

    return 0;
}

void kiemTra(vector<int> a){
    int n = a.size();
    for(int i=0 ; i<n-1 ; i++){
        if(a[i+1] <= a[i]){
            cout << i+1;
            return;
        }
    }
    cout << -1;
}