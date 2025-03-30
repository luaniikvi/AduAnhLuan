#include<iostream>
using namespace std;

int main()
{
    int m,n,x,y;
    cin >> m >> n >> x >> y;
    x--;y--;
    
    int a[100][100];

    for(int i= 0 ;i < m ; i++)
    {
        for(int j = 0; j < n ; j++)
        {
            cin >> a[i][j];
        }
    }

    long long total = a[x][y];
    int orix = x;
    int oriy = y;
    while(true)
    {
        x--;
        y--;
        if(x==-1 || y ==-1) break;
        total += a[x][y];
    }
    x = orix;
    y = oriy;
    while(true)
    {
        x--;
        y++;
        if(x==-1 || y == n) break;
        total += a[x][y];
    }
    x = orix;
    y = oriy;
    while(true)
    {
        x++;
        y++;
        if(x==m || y ==n) break;
        total += a[x][y];
    }
    x = orix;
    y = oriy;
    while(true)
    {
        x++;
        y--;
        if(x==m || y ==-1) break;
        total += a[x][y];
    }

    cout << total;

    return 0;
}