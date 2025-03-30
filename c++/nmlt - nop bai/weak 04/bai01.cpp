#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int size;cin >> size;
    vector<int> arr(size);

    for(int i=0;i<size;i++){
        cin >> arr[i];
    }

    vector<int> d(size-1);

    for(int i=0 ; i<size-1 ; i++){
        d[i] = abs(arr[i]-arr[i+1]);
    }

    cout << *min_element(d.begin(),d.end());

    return 0;
}