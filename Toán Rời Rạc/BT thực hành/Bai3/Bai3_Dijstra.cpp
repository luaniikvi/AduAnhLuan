// Lưu y: các đỉnh bắt đầu từ 0 đến n-1

#include <iostream>
#include<vector>
#define vvi vector<vector<int>> // mảng 2 chiều
#define vi  vector<int>         // mảng 1 chiều
#define inf 100000
using namespace std;
int n; // Số đỉnh
int s = 0; // Đỉnh bắt đầu
vi d;  // Đường đi ngắn nhất từ đỉnh S đến i
vi truoc;
vector<vector<string>> MaTranTrongSo;
void Start();
int w(int i, int j);
void format(int a);
void PrintPath(int e);
vi Delete(vi a, int val);
void Dijstra(){
    // Tạo mảng V chứa tất cả các đỉnh của đồ thị
    // Thứ tự có thể tùy theo đề bài yêu cầu
    // Nhưng thứ tự kh ảnh hướng đến kết quả
    vi V(n); for(int i=0 ; i<n ;i++) V[i] = i;
    // khởi tạo các giá trị theo thuật toán
    for(int v : V)
    {
        d[v] = w(s,v);
        truoc[v] = s;
    }
    d[s] = 0;
    vi T = Delete(V,s); // T = V\{s}

    // khi T != rỗng
    while(!T.empty())
    {
        // tìm u thuộc T sao cho d[u] = min{ d[z] | z thuộc T}
        // ->đơn giản là tìm u thuộc T sao cho d[u] bé nhất
        int u;
        int min_dz = inf;
        for(int z : T)
        {
            if(d[z] <= min_dz)
            {
                u = z;
                min_dz = d[z];
            }
        }
        T = Delete(T,u); // xóa {u} ra khỏi T
        for(int v : T)
        {
            if(d[v] > d[u] + w(u,v)){
                d[v] = d[u] + w(u,v);
                truoc[v] = u;
            }
        }
    }
}
int main()
{
    Start(); // lấy giá trị từ file
    Dijstra();
    // in ra đường đi
    for(int i=0 ; i<n ; i++)
    {
        if( i == s ) continue; // bỏ qua d[s] vì d[s] luôn = 0
        cout << "d["<<i<<"]:"; format(d[i]);
        PrintPath(i);// in ra đường đi từ s->i
    
        cout << endl;
    }
    // cout << "//inf: kh tồn tại đường đi";
    return 0;
}
void Start(){
    freopen("bai3.inp", "r", stdin);
    freopen("task.out", "w", stdout);

    cin >> n;
    d.resize(n);
    truoc.resize(n);
    vector<vector<string>> temp(n,vector<string>(n));
    for(auto &row : temp)
        for(auto &col : row)
                cin >> col;
    MaTranTrongSo = temp;
}
int w(int i, int j)
{   
    if(i == j) return 0;
    string num = MaTranTrongSo[i][j];
    if(!isdigit(num[0])) return inf;
    else return stoi(num);
}
void format(int a){
    if(a == inf) cout << "inf   ";
    else cout <<   a  << "      ";
}
void PrintPath(int e)
{
    // d[i] == vô cùng -> kh có đường đi từ s đến i
    if(d[e] == inf) cout << "Khong co duong di";
    // tạo mảng chứa đường đi
    else if(e == s)
    {
        cout << s;
        return;
    }
    PrintPath(truoc[e]);
    cout << "->" << e;
}
vi Delete(vi a, int val){
    vi del;
    for(int i : a)
        if(i == val) continue; // nếu = giá trị cần xóa -> đơn giản là bỏ qua
        else del.push_back(i);
    return del;
}