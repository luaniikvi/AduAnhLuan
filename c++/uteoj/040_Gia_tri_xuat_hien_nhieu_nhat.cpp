#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
    int n,input;
    cin >> n;
    unordered_map<int,int> frequent;
    for(int i=0 ; i<n ; i++)
    {
        cin >> input;
        frequent[input] ++;
    }

    int maxF = 0;
    int SpecNum = 0;
    for(auto &_pair : frequent)
    {
        if(_pair.second > maxF)
        {
            maxF = _pair.second;
            SpecNum = _pair.first;
        }
        else if(_pair.second == maxF)
        {
            if(_pair.first > SpecNum)
            {
                SpecNum = _pair.first;
            }
        }
    }

    cout << SpecNum;
    return 0;
}
