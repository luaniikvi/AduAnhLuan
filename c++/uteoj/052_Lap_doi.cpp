#include<iostream>
#include<vector>
using namespace std;

int giaiPhap(vector<vector<int>> a);

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n,vector<int>(3));

    for(vector<int> &j: a)
    {
        for(int &i : j)
        {
            cin >> i;
        }
    }

    cout << giaiPhap(a);

    return 0;
}

int Count(vector<int> a, int target)
{
    int count =0;
    for(int &i : a)
    {
        if(i == target) count++;

    }
    return count;
}

int giaiPhap(vector<vector<int>> a)
{
    int count = 0;
    for(vector<int> &bai : a)
    {
        if(Count(bai,1) >= 2) count ++;
    }
    return count;
}