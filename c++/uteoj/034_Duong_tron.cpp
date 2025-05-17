#include<iostream>
#include<vector>
using namespace std;

int shortestway(vector<int> dis,int x,int y);

int main()
{
    int n;
    cin >> n;
    vector<int> dis(n);
    for(int &i : dis) cin >> i;
    int x,y;
    cin >> x >> y;

    cout << shortestway(dis,x,y);

    return 0;
}

int shortestway(vector<int> dis,int x,int y)
{
    int n = dis.size();
    x--;y--;

    // tong duong tron
    int total = 0;
    for(int &num : dis)
    {
        total+=num;
    }

    // cung chieu
    int Cung_chieu = 0;
    for(int i=x ; i < y ; i++)
    {
        Cung_chieu += dis[i];
    }

    // nguoc chieu
    int Nguoc_chieu = total - Cung_chieu;

    return min(Cung_chieu,Nguoc_chieu);
}