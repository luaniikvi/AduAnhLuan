#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int> ori(n);

    for(int i=0;i<n;i++){
        cin >> ori[i];
    }
    
    long long Max = INT_MIN;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(ori[i]==ori[j]) continue;
            Max = max(Max,1LL*ori[i]*ori[j]);
        }
    }

    cout << (Max == INT_MIN ? 0 : Max);

    return 0;
}