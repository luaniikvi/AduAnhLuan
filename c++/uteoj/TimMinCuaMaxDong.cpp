#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
int main()
{
    int m,n;cin >> m >> n;
    vector<vector<int>> matrix(m,vector<int>(n));

    for(vector<int> &d : matrix)
    {
        for(int &i : d) cin >> i;
    }

    int _min = INT_MAX;
    for(vector<int> &d : matrix)
    {
        _min = min(_min,*max_element(d.begin(),d.end()));
    }

    cout << _min;

    return 0;
}