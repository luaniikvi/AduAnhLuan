#include<iostream>
using namespace std;
int main()
{
    int m,n;
    cin >> m >> n;
    int a[100][100];
    int max_num;
    for(int i=0 ; i< m ; i++)
    {
        for(int j=0 ; j<n ; j++) cin >> a[i][j];
    }

    for(int i=0 ; i<n ; i++)
    {
        if(i == 0) max_num = a[m/2][i];
        else max_num = max(max_num,a[m/2][i]);
    }

    cout << max_num;
    return 0;
}