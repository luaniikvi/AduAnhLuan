#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n,W; cin >> n >> W;

    vector<int> w(n);
    for(auto &i : w) cin >> i;
    if(!n)
    {
        cout << 0;
        return 0;
    }
    sort(w.begin(),w.end(),greater<int>());

    int car = 1;
    int weight = 0;
    for(auto i : w)
    {
        if(weight + i < W) weight+=i;
        else if (weight + i == W){
            weight = 0;
            car++;
        }
        else {
            weight = i;
            car++;
        }
    }
    cout << car;
    return 0;
}