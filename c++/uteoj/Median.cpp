#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int GetTV(vector<int> a)
{
    sort(a.begin(),a.end());
    return a[(a.size()-1)/2];
}

int main()
{
    int n,k;
    cin >> n >> k;

    vector<int> a(n);
    vector<int> temp(k);
    vector<int> TVs;

    for(int &i : a) cin >> i;
    
    for(int i=0 ; i<n-k+1 ; i++)
    {
        for(int j = 0; j<k ; j++)
        {
            temp[j]= a[j+i];
        }
        TVs.push_back(GetTV(temp));
        //cout << GetTV(temp);
    }

    
    cout << GetTV(TVs) << endl;

}