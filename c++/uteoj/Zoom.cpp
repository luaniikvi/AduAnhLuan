#include<iostream>
#include<vector>
using namespace std;

void PrintScale(vector<char> a , int scale_x, int scale_y)
{
    for(int i=0 ; i <scale_x ; i++)
    {
        for(char c : a)
            for(int j=0 ; j<scale_y ; j++) cout << c;
        cout << endl;
    }
}

int main()
{
    int size_x,size_y,scale_x,scale_y;
    cin >> size_x >> size_y >> scale_x >> scale_y;

    vector<vector<char>> a(size_x,vector<char>(size_y));
    for(vector<char> &d : a)
    for(char &c : d) cin >> c;

    for(vector<char> d : a)
    PrintScale(d,scale_x,scale_y);
}