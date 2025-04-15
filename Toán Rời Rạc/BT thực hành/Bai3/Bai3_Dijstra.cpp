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
int compare(int sum);
void format(int a);
void PrintPath(int e);
vi Delete(vi a, int val);
void Dijstra(){
    // Tạo mảng V chứa tất cả các đỉnh của đồ thị
    vi V(n); for(int i=0 ; i<n ;i++) V[i] = i;
    // khởi tạo các giá trị theo thuật toán
    for(auto v : V)
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
        for(auto v : T)
        {
            int f = compare(d[u] + w(u,v));
            if(d[v] > f){
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
    for(int i=1 ; i<n ; i++)
    {
        cout << "d["<<i<<"]: "; format(d[i]);
        PrintPath(i);// in ra đường đi
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
int compare(int sum){
    return min(sum,inf);
}
void format(int a){
    if(a == inf) cout << "inf ";
    else cout << a << ' ';
}
void PrintPath(int e)
{
    if(d[e] == inf) return;
    vi paths;
    while(e != s)
    {
        paths.push_back(e);
        e = truoc[e];
    }
    cout << s;
    for(int i=paths.size()-1 ; i>=0 ; i--)
        cout << "->" << paths[i];
}
vi Delete(vi a, int val){
    vi del;
    for(auto i : a)
        if(i == val) continue;
        else del.push_back(i);
    return del;
}