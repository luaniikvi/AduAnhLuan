#include<iostream>
#include<vector>
#include<queue>
#include<map>

#define fast 
#define file(name) freopen(name".inp","r",stdin); freopen(name".out","w",stdout);

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
    fast;
    //file("task");
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
