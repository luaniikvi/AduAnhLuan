#include <iostream>
#include <vector>
//#pragma GCC optimize("O2")
using namespace std;
struct Tree {
    long x, h;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);// TCCL
    long N; cin >> N;

    vector<Tree> trees(N);
    for (long i = 0; i < N; ++i) cin >> trees[i].x;
    for (long i = 0; i < N; ++i) cin >> trees[i].h;

    if (N == 0) 
    {
        cout << 0;
        return 0;
    }

    long count = 1; // cây bên trái luôn đổ đc về bên trái
    long last_pos = trees[0].x; // Vị trí cuối cùng bị chiếm

    for (long i = 1; i < N; ++i) {
        bool can_fall_left = (trees[i].x - trees[i].h >= last_pos);
        // nếu cây cuối thì có thể đổ về phải
        bool can_fall_right = (i == N - 1) || (trees[i].x + trees[i].h <= trees[i + 1].x);

        if (can_fall_left) {
            count++;
            last_pos = trees[i].x; // Cây i đổ trái, nên vị trí cuối cùng là trees[i].x
        } else if (can_fall_right) {
            count++;
            last_pos = trees[i].x + trees[i].h; // Cây i đổ phải
        } else 
            last_pos = trees[i].x; // Không cưa cây i
    }

    cout << count;
    return 0;
}