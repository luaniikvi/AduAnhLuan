#include<bits/stdc++.h>
using namespace std;      
int a[30];
bool check[30];
int n,m;
void xuat(){
      for(int i = 0; i < n; i++) cout << a[i] << " ";
      cout << '\n';
}
//Sinh nhị phân
void sinhNP(int k){
      if (k == n){
            xuat();
            return;
      }
      for(int i = 0; i <= 1; i++){
            a[k] = i;
            sinhNP(k+1);
      }
}
//Sinh hoán vị
void sinhHV(int k){
      if (k > n){
            xuat();
            return;
      }
      for(int i = 1; i <= n; i++)
      if (!check[i]){
            a[k] = i;
            check[i] = true;
            sinhHV(k+1);
            check[i] = false; 
      }
}

void xuatCH(){
      for(int i = 1; i <= n; i++)
      if (check[a[i]]) cout << a[i] << " ";
      cout << '\n';
}
//Sinh chỉnh hợp không lặp
void sinhCH(int k){
      if (k > m){
            xuatCH();
            return;
      }
      for(int i = 1; i <= n; i++)
      if (!check[i]){
            a[k] = i;
            check[i] = true;
            sinhCH(k+1);
            check[i] = false;
      }
}
void solve(){
      n = 5;
      m = 3;
      sinhCH(1); //sinh chỉnh hợp 5 chập 3
      sinhHV(1); //sinh hoán vị 1 -> 5
      sinhNP(0); //sinh nhị phân có độ dài 5
}
signed main()
{
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
      int t = 1;
      if (t > 1) cin >> t;
      while(t--){
            solve();
      }
}

////////////////////////////////////////////////////////////////////////////////////////////


#include<iostream>
#include<vector>
#include<queue>
#include<map>

using namespace std;

struct point{
    int x=-1, y=-1;
    point(){};
    point(int a, int b): x(a), y(b){};

    void operator=(point other)
    {
        this->x = other.x;
        this->y = other.y;
    }

    bool operator== (point other)
    {
        return x == other.x && y == other.y;
    }

    point operator+ (point other)
    {
        return point(x+other.x, y+other.y);
    }

    bool isnull(){
        return (this->x==-1 && this->y==-1);
    }

};

int m,n;point Start,End;

vector<vector<char>> a;
vector<vector<bool>> chuaxet;

map< pair<int,int> , pair< point, char >> truoc;
queue<point> que;

point d[] = {point(-1,0), point(1,0), point(0,-1), point(0,1)};
string direction="UDLR";

bool BFS(point Start, point End);

int main()
{
    cin >> m >> n;
    a.resize(m,vector<char>(n));
    chuaxet.resize(m,vector<bool>(n,true));    

    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            cin >> a[i][j];
            if(a[i][j] == 'A') Start = point(i,j);
            else if(a[i][j] == 'B') End = point(i,j);
        }
    }

    if(Start.isnull() || End.isnull()){
        cout << "NO" << endl;
        return 0;
    }

    if(BFS(Start,End))
    {
        cout << "YES" << endl;
        // print path
        string path = "";
        while(!(End == Start)){
            path += truoc[{End.x,End.y}].second;
            End = truoc[{End.x,End.y}].first;
        }
        cout << path.length() << endl;
        int i = path.length()-1;
        while (i>=0) cout << path[i--];
        cout << endl;

    }
    else cout << "NO" << endl;
    return 0;
}

bool isValid(point p)
{
    int i = p.x;
    int j = p.y;
    return i>=0 && i<m && j>=0 && j<n && a[i][j] != '#' && chuaxet[i][j];
}

bool BFS(point Start, point End){
    if(Start == End) return true;
    chuaxet[Start.x][Start.y] == false;
    que.push(Start);
    while(!que.empty())
    {
        point curr = que.front();que.pop();
        if(curr == End) return true;

        for(int i=0 ; i<4 ; i++)
        {
            point next = curr + d[i];
            if(isValid(next))
            {
                chuaxet[next.x][next.y] = false;
                que.push(next);
                truoc[{next.x,next.y}] = {curr,direction[i]};
            }
        }

    }
    return false;
}

///////////////////////////////////////////////////////////////////////////////////



#include <iostream>
#include <vector>
#include <climits>

#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define file(name) freopen(name".inp","r",stdin); freopen(name".out","w",stdout);

using namespace std;

int main() {
    faster;

    int m, n, start_r, start_c, k;
    cin >> m >> n >> start_r >> start_c >> k;

    vector<vector<int>> h(m, vector<int>(n));
    for (auto &i : h)
        for (int &j: i )
            cin >> j;

    int r = start_r - 1;
    int c = start_c - 1;
    int time = 0;

    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int step = 0; step < k; ++step) {
        if (r == 0 || r == m - 1 || c == 0 || c == n - 1) {
            cout << "YES\n" << time << "\n";
            return 0;
        }

        int min_h = INT_MAX, nr = -1, nc = -1;
        for (int i = 0; i < 8; ++i) {
            int tr = r + dr[i], tc = c + dc[i];
            if (tr >= 0 && tr < m && tc >= 0 && tc < n && h[tr][tc] < min_h) {
                min_h = h[tr][tc];
                nr = tr;
                nc = tc;
            }
        }

        r = nr;
        c = nc;
        ++time;
    }

    cout << "NO\n" << (r + 1) << " " << (c + 1) << endl;
    return 0;
}