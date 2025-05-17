#include <iostream>
#include <vector>
using namespace std;
int m,n;
vector<string> grid;
vector<vector<bool>> chuaxet;
bool validFloor(int i, int j)
{
    return i>=0 && i< n && j>=0 && j<m && grid[i][j] == '.' && chuaxet[i][j];
}

int ver[] = {-1,1,0,0};
int hor[] = {0,0,-1,1};
void dfs(int i, int j){
    chuaxet[i][j] = false;
    for(int k=0 ; k<4 ; k++)
    {
        int near_i = i + ver[k];
        int near_j = j + hor[k];
        if(validFloor(near_i,near_j)) dfs(near_i,near_j);
    }
}

int main()
{
    cin >> n >> m;
    grid.resize(n);
    for(string &s : grid) cin >> s;
    chuaxet.resize(n,vector<bool>(m,1));

    int roomcount = 0;
    for(int i=0 ; i<n ; i++)
        for(int j=0 ; j<m ; j++)
            if(grid[i][j] == '.' && chuaxet[i][j])
            {
                dfs(i,j);
                roomcount++;
            }
    cout << roomcount;
    return 0;
}