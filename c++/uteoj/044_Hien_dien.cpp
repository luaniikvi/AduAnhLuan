#include<iostream>
#include<vector>
using namespace std;

bool check(vector<vector<int>>a,vector<vector<int>> b);

int main()
{
    int m,n,x,y;
    cin >> m >> n >> x >> y;

    vector<vector<int>> a(m,vector<int>(n));
    vector<vector<int>> b(x,vector<int>(y));
    
    for(vector<int> &i : a)
    {
        for(int &j : i) cin >> j;
    }
    for(vector<int> &i : b)
    {
        for(int &j : i) cin >> j;
    }
    
    cout << (check(a,b) ? "YES":"NO" ); 

    return 0;
}


bool equal(vector<vector<int>>a,vector<vector<int>> b,int i0, int j0)
{
    int mb = b.size();
    int nb = b[0].size();
    for(int i=i0 ; i<i0+mb ; i++)
    {
        for(int j=j0 ; j<j0+nb; j++)
        {
            if(a[i][j] != b[i-i0][j-j0])
            {
                return false;
            }
        }
    }

    return true;
}

bool check(vector<vector<int>>  a,vector<vector<int>> b)
{
    int ma = a.size();
    int na = a[0].size();
    int mb = b.size();
    int nb = b[0].size();
    for(int i = 0 ; i<=(ma - mb) ; i++)
    {
        for(int j=0 ;j<=(na - nb);j++)
        {
            if(a[i][j] == b[0][0])
            {
                if(equal(a,b,i,j)){
                    return true;
                }
            }
        }
    }

    return false;
}