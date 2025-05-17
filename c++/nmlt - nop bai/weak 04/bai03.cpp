#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long getMaxM(vector<int> a);
//vector<int> Normalize(vector<int> a);


int main(){
    int n;cin>>n;
    vector<int> ori(n);

    for(int i=0;i<n;i++){
        cin >> ori[i];
    }

    cout << getMaxM(ori);
    
    return 0;
}

bool isApear(int tar, vector<int> a)
{
    for(int i : a)
    {
        if(i == tar) return true;
    }
    return false;
}

vector<int> Normalize(vector<int> a)
{
    vector<int> nor;
    for(int &i : a)
    {
        if(!isApear(i,nor)) nor.push_back(i);
    }

    return nor;

}

long long getMaxM(vector<int> a)
{
    long long t = 1;
    vector<int> nor = Normalize(a);
    if(nor.size() < 2)
    {
        return 1;
    }
    sort(nor.begin(),nor.end());
    t *= nor.back();
    nor.pop_back();
    t *= nor.back();

    return t;
}