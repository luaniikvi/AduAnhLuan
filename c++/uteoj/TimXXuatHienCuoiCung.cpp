#include<iostream>
using namespace std;
int main()
{
    int n,tar;
    cin >> n >> tar;
    int input,pos =-1;
    for(int i =0 ;i< n; i++)
    {
        cin >> input;
        if(input == tar) pos = i;
    }
    cout << pos;
}