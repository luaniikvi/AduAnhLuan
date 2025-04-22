// Lưu y: các đỉnh bắt đầu từ 0 đến n-1

#include<iostream>
#include<vector>
#include<sstream>
#include<queue>
using namespace std;
#define vvi vector<vector<int>> // viết tắt mảng 2 chiều cho ma trận trọng số
#define vi vector<int>          // viết tắt mảng 1 chiều
int n;                          // số đỉnh
vvi MaTranKe;                   // ma trận kề
vi d;                           // độ dài đường đi (từ đỉnh S)
vi ChuaXet;                     // đánh dấu các đỉnh

int root = 1;             // vị trí bắt đầu
vi ThuTuXet = {4,0,6,3,1,7,5,2,8}; // Thứ tự xét (mặc định là từ bé đến lớn) = {0,1,..,n-1}
vi Ke(int v);// Tìm các đỉnh kề
void Start();// truy xuất dữ liệu
struct Path  // đường đi (có hướng)
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
        return this->data.size();
    }
    // in ra dữ liệu của T
    friend ostream& operator<<(ostream& os , Tree tree)
    {
        os << "{";
        for(int i=0 ; i<tree.size()-1 ; i++)
            os << tree.data[i].pair() << ",";
        os << tree.data.back().pair() << "}";
        return os;
    }
};

Tree T;         // chứa các cạnh của cây khung
void Tree_BFS(int r){
    vi V(n);        // các đỉnh {0..n-1}
    for(int i=0 ; i<n ; i++) V[i] = i;

    queue<int> que; // tạo hàng chờ
    que.push(r);    // thêm r vào hàng chờ
    ChuaXet[r] = 0;

    // Khi QUEUE != rỗng
    while(!que.empty())
    {
        int v = que.front();que.pop(); // Lấy giá trị lưu vào v
        for(int u : Ke(v)){
            if(ChuaXet[u])
            {
                que.push(u); // thêm u vào hàng chờ
                ChuaXet[u] = 0;
                // thêm cặp (v,u) vào trong T
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
    return 0;
}

vi Ke(int v) // Tìm các đỉnh kề
{
    vi _ke;
    if(ThuTuXet.empty()) // Nếu rỗng xét theo chiều từ bé đến lớn
    {
        for(int i=0 ; i<n ; i++)
        {
            if(i == v) continue;
            if(MaTranKe[i][v] >= 1)
                _ke.push_back(i);
        }
    }
    else    // Xét theo chiều quy ước
        for(auto i : ThuTuXet)
        {
            if(i == v) continue;
            if(MaTranKe[i][v] >=1)
                _ke.push_back(i);
        }
    return _ke;
}
void Start(){
    freopen("Bai5.inp","r",stdin);
    freopen("task.out","w",stdout);
    cin >> n;

    // Nhập ma trận kề
    vvi temp(n,vi(n));
    for(auto &row : temp)
        for(auto &col : row)
            cin >> col;
    MaTranKe = temp;
    // ChuaXet[i] = 1;
    ChuaXet.resize(n,1);
}