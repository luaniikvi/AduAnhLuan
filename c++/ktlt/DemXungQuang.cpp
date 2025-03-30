#include<iostream>
using namespace std;

int Count(char a[100][100],int i0,int j0,int m,int n)
{
    int count = 0;
    if(a[i0][j0+1] == '*' &&  j0+1 < n) count++;
    if(a[i0][j0-1] == '*' &&  j0-1 >= 0) count++;
    if(a[i0+1][j0] == '*' &&  i0+1 < m) count++;
    if(a[i0-1][j0] == '*' &&  i0-1 >= 0) count++;
    return count;
}

void Change(char a[100][100], int m, int n)
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(a[i][j] == '*') continue;
            a[i][j] = Count(a,i,j,m,n) + '0';
        }
    }
}


int main()
{   
    int m,n;
    cin >> m >> n;

    char a[100][100];
    //cin 
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << "\n\n" << endl;
    // do somthing
    Change(a,m,n);

    //print vector
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}