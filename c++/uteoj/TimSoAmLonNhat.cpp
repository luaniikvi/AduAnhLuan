#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int max_negative(vector<int> a);

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &n : a)
    {
        cin >> n;
    }

    cout << max_negative(a);

    return 0;
}

int _max(int a,int b)
{
    return (a>b ? a : b);
}

int max_negative(vector<int> a)
{   
    int max = INT_MIN;
    for(int &n : a)
    {
        if(n<0)
        {
            max = _max(max,n);
        }
    }
    return (max == INT_MIN ? 0 : max);
}