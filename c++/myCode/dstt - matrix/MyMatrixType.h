#include<iostream>
#include<vector>
#include<sstream>
#define vvi vector<vector<int>>
#define vi vector<int>
using namespace std;


class Msize
{
public:
    int m;
    int n;
    Msize() : m(0) , n(0){}
    Msize(int row, int col)
    {
        this->m = row;
        this->n = col;
    }
};
class Matrix
{
public:
    vvi value;
    Msize size;
    bool isempty = true;
    Matrix()
    {
        this->value = {{}};
    }
    Matrix(vvi A)
    {
        this->value = A;
        this->size = Msize(A.size(),A[0].size());
        if(size.m != 0 && size.n != 0) isempty = false;
    }

    friend ostream &operator<<(ostream &os, Matrix a)
    {
        for (int i = 0; i < a.size.m; i++)
        {
            for (int j = 0; j < a.size.n; j++)
            {
                os << a.value[i][j] << ' ';
            }
            os << "\n";
        }
        return os;
    }

    friend istream &operator>>(istream &is, Matrix &a)
    {
        if(!a.empty())
        {
            int control = -1;
            cout << "Ma tran da ton tai. (value): "  << endl;
            cout << a;
            cout << "Ban co muon tao lai?" << endl;
            cout << "(1 : yes     0 : no)" << endl;
            cout << "-->";
            cin >> control;
            if(!control) return is;
        }
        cout << "Nhap size(m x n): ";
        cin >> a.size.m;
        cin >> a.size.n;
        cout << "Nhap ma tran:" << endl;
        vvi temp(a.size.m, vi(a.size.n));
        for (vi &row : temp)
            for (int &col : row)
            {
                cin >> col;    
                a.isempty = false;            
            }
        a.value = temp;
        temp.clear();
        return is;
    }



    Matrix& operator=(const Matrix& other)
    {
        if (this != &other)
        {
            this->size = other.size;
            this->value = other.value;
        }
        if(size.m != 0 && size.n != 0) isempty = false;
        return *this;
    } 
    Matrix& operator=(const vvi& other)
    {

        this->size.m = other.size();
        this->size.n = other[0].size();
        this->value = other;
        if(size.m != 0 && size.n != 0) isempty = false;
        return *this;
    } 

    bool empty()
    {
        return this->isempty;
    }
};


string IntToStr(int num)
{
    stringstream ss;
    ss << num;
    return ss.str();
}