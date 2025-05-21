//                       _oo0oo_
//                      o8888888o
//                      88" : "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \\|     |// '.
//                 / \|||   :  |||// \
//                / _||||| -:- |||||- \
//               |   | \\\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====

//                       `=---='
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
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
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> h[i][j];

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