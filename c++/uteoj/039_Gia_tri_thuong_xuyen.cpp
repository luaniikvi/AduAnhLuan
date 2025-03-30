#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int input;
    unordered_map<int,int> frequent;
    for(int i=0 ; i<n ;i++)
    {
        cin >> input;
        frequent[input]++; 
    }

    int dem =0;
    for(auto &_pair : frequent)
    {
        if(_pair.second > 2) dem++;
    }

    cout << dem;


    return 0;
}