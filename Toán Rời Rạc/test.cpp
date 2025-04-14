#include<iostream>
using namespace std;

int main()
{
    freopen("bai3.inp","r",stdin);
    freopen("task.out","w",stdout);

    int a[4][4];
    int n;cin >> n;
    for(int i=0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
            cin >> a[i][j];
    for(int i=0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
        

    return 0;
}