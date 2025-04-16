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
vi Truoc;
vector<vector<string>> MaTranTrongSo;
void Start();
int w(int i, int j);
int compare(int a,int b);
void format(int a);
void PrintPath(int e);
vi Delete(vi a, int val);
void Ford_Bellman(){
    // Tạo mảng V chứa tất cả các đỉnh của đồ thị
    // Thứ tự có thể tùy theo đề bài yêu cầu
    // Nhưng thứ tự kh ảnh hướng đến kết quả
    vi V(n);for(int i=0 ; i<n ; i++) V[i] = i; // mặc định là tăng dần
    // khởi tạo các giá trị theo thuật toán
    for(int v : V)
    {
        d[v] = w(s,v);
        Truoc[v] = s;
    }
    d[s] = 0;

    for (int k = 1; k < n-1; k++) // n : số đỉnh
        for(int v : Delete(V,s))  //for (v ∈ V \ {s})
            for(int u : V)        //for (u ∈ V)
                if (d[v] > compare(d[u],w(u,v)))
                {
                    d[v] = d[u] + w(u,v);
                    Truoc[v] = u;
                }
}// Kết thúc Ford_Bellman()
int main()
{
    Start(); // lấy giá trị từ file
    Ford_Bellman();
    // in ra đường đi
    for(int i=0 ; i<n ; i++)
    {
        if( i == s ) continue; // bỏ qua d[s] vì d[s] luôn = 0
        cout << "d["<<i<<"]:"; format(d[i]);
        PrintPath(i);// in ra đường đi
        cout << endl;
    }
    // cout << "//inf: kh tồn tại đường đi";
    return 0;
}
void Start(){
    freopen("bai4.inp", "r", stdin);
    freopen("bai4.out", "w", stdout);

    cin >> n;
    d.resize(n);
    Truoc.resize(n);
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
    if(!isdigit(num[0]) && num[0] != '-') return inf;
    else return stoi(num);
}
int compare(int a, int b) // hàm tồn tại với mục đích so sánh các giá trị liên quan với vô cùng
{
    if(a == inf || b == inf)
        return inf;
    return a+b;
}
void format(int a){
    if(a == inf) cout << "inf   ";
    else cout <<   a  << "      ";
}
void PrintPath(int e)
{
    // d[i] == vô cùng -> kh có đường đi từ s đến i
    if(d[e] == inf){
        cout << "Khong co duong di";
        return;
    }
    // tạo mảng chứa đường đi
    vi paths;
    while(e != s)
    {
        paths.push_back(e);
        e = Truoc[e];
    }
    cout << s;// điểm s
    // các điểm sau đó
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