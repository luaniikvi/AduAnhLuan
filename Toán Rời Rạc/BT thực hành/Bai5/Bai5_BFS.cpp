#include<iostream>
#include<vector>
#include<sstream>
#include<queue>
using namespace std;
#define vvi vector<vector<int>> // mảng 2 chiều cho ma trận trọng số
#define vi vector<int>          // mảng 1 chiều
int n;                          // số đỉnh
vvi MaTranKe;                   // ma trận kề
vi d;                           // độ dài đường đi (từ đỉnh S)
vi ChuaXet;                     // đánh dấu các đỉnh
vi V;                           // các đỉnh
int root = 0;                   // vị trí bắt đầu 
vi Ke(int v);
void Start();
struct Path // đường đi (có hướng)
{
    vi _direction;
    Path(int s, int e){
        _direction = {s,e};
    }
    string pair()
    {
        stringstream ss;
        ss << "(" << _direction[0] << "," << _direction[1] << ")";
        return ss.str();
    }
};
struct Tree{
    vector<Path> data;
    Tree(){};
    void add(Path p)
    {
        this->data.push_back(p);
    }
    int size(){
        this->data.size();
    }
    // in ra dữ liệu của T
    friend ostream& operator<<(ostream& os , Tree tree)
    {
        os << '{';
        for(int i=0 ; i<tree.size()-1 ; i++)
            os << tree.data[i].pair() << ',';
        os << tree.data.back().pair() << "}";
        return os;
    }
};
Tree T;
void Tree_BFS(int r){
    queue<int> que; // tạo hàng chờ
    que.push(r);
    ChuaXet[r] = 0;
    while(!que.empty())
    {
        int v = que.front();que.pop();
        for(int u : Ke(v)){
            if(ChuaXet[u])
            {
                que.push(u);
                ChuaXet[u] = 0;
                T.add(Path(v,u));
            }
        }
    }
}
int main()
{
    Start(); // đọc dữu liệu từ file
    Tree_BFS(root);
    cout << T;
}

vi Ke(int v) // Tìm các đỉnh kề
{
    vi _ke;
    for(int i=0 ; i<n ; i++)
    {
        if(i == v) continue;
        if(MaTranKe[i][v] >= 1)
            _ke.push_back(i);
    }
    return _ke;
}
void Start(){
    freopen("Bai5.inp","r",stdin);
    freopen("task.out","w",stdout);
    cin >> n;
    vvi temp(n,vi(n));
    for(auto &row : temp)
        for(auto &col : row)
            cin >> col;
    MaTranKe = temp;
    ChuaXet.resize(n);
    V.resize(n);
    for(int i=0 ; i<n ; i++) V[i] = i;
    for(int i=0 ; i<n ; i++) ChuaXet[i] = 1;
}