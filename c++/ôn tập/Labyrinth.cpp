#include <vector>
#include <iostream>
#include <queue>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

struct point {
    int x, y;
    point() : x(-1), y(-1) {};
    point(int a, int b) : x(a), y(b) {}

    point operator+(point other) {
        return point(x + other.x, y + other.y);
    }

    point operator-(point other) {
        return point(x - other.x, y - other.y);
    }

    bool operator==(point other) {
        return (x == other.x && y == other.y);
    }
    void operator=(point p) {
        this->x = p.x;
        this->y = p.y;
    }
    void operator=(vector<int> a) {
        this->x = a[0];
        this->y = a[1];
    }
};

queue<point> que;
vector<vector<int>> visited;
vector<vector<char>> a;
map<pair<int, int>, pair<point, char>> parent; // Lưu trữ cha và hướng đi
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
string dir = "UDLR";
int m, n;

bool isValid(point p) {
    return p.x >= 0 && p.y >= 0 && p.x < m && p.y < n && visited[p.x][p.y] && a[p.x][p.y] != '#';
}

bool BFS(point start, point end) {
    visited[start.x][start.y] = false;
    que.push(start);

    while (!que.empty()) {
        point current = que.front();
        que.pop();

        if (current == end) {
            return true;
        }

        for (int i = 0; i < 4; ++i) {
            point next = current + point(dr[i], dc[i]);
            if (isValid(next)) {
                visited[next.x][next.y] = false;
                parent[{next.x, next.y}] = {current, dir[i]};
                que.push(next);
            }
        }
    }
    return false;
}

int main() {
    //freopen("task.inp","r",stdin);
    //freopen("task.out","w",stdout);
    point start, end;

    cin >> m >> n;

    visited.resize(m, vector<int>(n, 1));
    a.resize(m, vector<char>(n));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 'A') start = point(i, j);
            else if (a[i][j] == 'B') end = point(i, j);
        }
    }

    if (start == point(-1, -1) || end == point(-1, -1)) {
        cout << "NO" << endl;
        return 0;
    }

    if (BFS(start, end)) {
        cout << "YES" << endl;
        string path = "";
        point curr = end;
        while (!(curr == start)) {
            path += parent[{curr.x, curr.y}].second;
            curr = parent[{curr.x, curr.y}].first;
        }
        reverse(path.begin(), path.end());
        cout << path.length() << endl;
        cout << path << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}