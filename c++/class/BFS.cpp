#include<iostream>
#include<vector>
#include<sstream>
using namespace std;
#define vvi vector<vector<int>> // mảng 2 chiều cho ma trận trọng số
#define vi vector<int>          //  mảng 1 chiều
int n;                          // số đỉnh
vvi MaTranTrongSo,MaTranKe;     // 2 loại ma trận
vi d;                           // độ dài đường đi (từ đỉnh S)
vi ChuaXet;
void ReSize();
void input(vvi &Matrix);
vi Ke(int v);

struct Path{
    vi _direction;
    int _len = 0;
    Path(int s, int e){
        _direction = {s,e};
        _len = MaTranTrongSo[s][e];
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
    friend ostream& operator<<(ostream& os , Tree tree)
    {
        os << '{';
        for(int i=0 ; i<tree.size()-1 ; i++)
            os << tree.data[i].pair() << ',';
        os << tree.data.back().pair() << "}";
        return os;
    }
};

int main()
{
    cin >> n;
    ReSize();
    
}

void ReSize()
{
    MaTranTrongSo.resize(n);
    MaTranKe.resize(n);
    for(int i=0 ; i<n ; i++)
    {
        MaTranKe[i].resize(n);
        MaTranTrongSo[i].resize(n);
    }
    d.resize(n);
    ChuaXet = vector<int>(n,1); // set full-true
}
void input(vvi& Matrix)
{
    for(auto &row : Matrix)
        for(auto &col : row)
            cin >> col;
}
vi Ke(int v)
{
    vi ke;
    for(int i=0 ; i<n ; i++)
    {
        if(i == v) continue;
        if(MaTranKe[i][v] == 1) ke.push_back(i);
    }
    return ke;
}