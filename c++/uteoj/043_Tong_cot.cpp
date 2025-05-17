#include<iostream>
using namespace std;
int main()
{
    int m,n;
    cin >> m >> n;
    long long a[100][100];

    for(int i= 0 ;i < m ; i++)
    {
        for(int j= 0 ; j < n ; j++)
        {
            cin >> a[i][j];
        }
    }

    long long int sum = 0;
    for(int c = 0 ; c < n ; c++)
    {
        for(int h = 0 ; h< m ; h ++)
        {
            sum += a[h][c];
        }
        cout << sum << " ";
        sum = 0;
    }

    return 0;
}