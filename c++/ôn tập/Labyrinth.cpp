#include <bits/stdc++.h>
using namespace std;
int m,n;
vector<vector<char>> grid;
vector<vector<int>> dp;
vector<vector<char>> trc;
int dr[] = {-1,1,0,0};
int dc[] = {0,0,-1,1};
char dir[] = {'U','D','L','R'};

bool dps(int i,int j)
{
    if(grid[i][j] == 'B') return true;
    for(int k=0 ; k<4 ; k++)
    {
        int nr = i + dr[k];
        int nc = j + dc[k];
        if(nr>=0 && nc >=0 && nr < n && nc < m && grid[nr][nc] != '#')
        {
            if(dp[nr][nc] > dp[i][j] + 1)
            {
                dp[nr][nc] = dp[i][j] + 1;
                trc[nr][nc] = dir[k];
            }
            if(dps(nr,nc)) return true;
        }
    }
    return false;
}

int main()
{
    //freopen("task.inp","r",stdin);
    //freopen("task.out","w",stdout);
    cin >> n >> m;

    grid.resize(n,vector<char>(m));
    dp.resize(n,vector<int>(m,INT_MAX-1));
    trc.resize(n,vector<char>(m));

    int start_i,start_j,end_i,end_j;  
    
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            cin >> grid[i][j];
            if(grid[i][j] == 'A'){
                start_i = i;
                start_j = j;
                dp[i][j] = 0;
            }
            else if(grid[i][j] == 'B'){
                end_i = i;
                end_j = j;
            }
        }
    }
    //cout << dps(start_i,start_j);
    return 0;
}