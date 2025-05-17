#include<vector>
#include<sstream>
#include<conio.h>
#define vvi vector<vector<int>>
#define vi vector<int>
using namespace std;

class Msize
{
public:
    int m;
    int n;
    Msize()
    {
        this->m = 0;
        this->n = 0;
    }
    Msize(int row, int col)
    {
        this->m = row;
        this->n = col;
    }
};
class Matrix
{
    vvi value;
    Msize size;
    friend istream& operator>> (istream &is,Matrix &a)
    {
        cout << "Input size(m x n): ";
        cin >> a.size.m;
        cin >> a.size.n;
        vvi temp(a.size.m,vi(a.size.n));
        for(vi &row : temp)
            for(int &col : row) cin >> col;
        a.value = temp;
        temp.clear();
        return is;
    }

    friend ostream& operator<<(ostream& os, Matrix a)
    {
        for(int i=0 ; i<a.size.m ; i++)
        {
            for(int j= 0 ; j <a.size.n ; j++)
            {
                os << a.value[i][j] << ' ';
            }
            os << "\n";
        }
        return os;
    }
};


void PrintMenu();
string IntToStr(int num)
{
    stringstream ss;
    ss << num;
    return ss.str();
}
void InputMaxtrix(vvi &A,int m , int n)
{
    cout << "Nhap ma tran:\n";
    vector<int> temp_a;
    int ptu;
    for(int i=0 ; i<m ; i++)
    {
        for(int j = 0; j<n ; j++)
        {
            cin >> ptu;
            temp_a.push_back(ptu);
        }
        A.push_back(temp_a);
        temp_a.clear();
    }
}
void PrintMatrix(vvi A)
{
    for(vector<int> d : A)
    {
        for(int c : d)
                cout << c << " ";cout << endl;
    }
}
void PauseKeyboard()
{
    cout << "ENTER to continue...";
    _getch();
}
vvi CopyMatrix(char chooseMatrix, vvi A, vvi B, vvi C , vvi D)
{
    switch (chooseMatrix)
    {
    case 'a':
        return A;
    
    case 'b':
        return B;
    
    case 'c':
        return C;
    
    case 'd':
        return D;
    }
    return vvi(0,vector<int>(0));
}
string GetSize(char choose,vvi a,vvi b,vvi c,vvi d)
{
    vvi matrix = CopyMatrix(choose,a,b,c,d);
    string size = "(";
    size += IntToStr(matrix.size());
    size += 'x';
    size += IntToStr(matrix[0].size());
    size += ')';
    return size;
}
int _1pow(int n)
{
    if(n%2 == 0) return 1;
    return -1;
}
// phan bu ds
vvi Algebraic_complement(vvi a, int i, int j)
{
    vvi vt;
    int size = a.size();
    vector<int> tempC;
    for(int h = 0 ; h < size ; h++)
    {
        if (h == i) continue;
        for(int c =0;  c < size ; c++)
        {
            if(c == j) continue;
            tempC.push_back(a[h][c]);
        }
        vt.push_back(tempC);
        tempC.clear();
    }
    return vt;
}
vvi BuDs(vvi a, int i, int j)
{
    return Algebraic_complement(a,i,j);
}

long long Det(vvi a)
{
    if(a.empty()) return 0;

    int size_m = a.size();
    int size_n = a[0].size();

    if(size_m != size_n) return 0;
    else
    {
        if(size_m == 1)
        {
            return a[0][0];
        }
        else if(size_m == 2)
        {
            return a[0][0]*a[1][1] - a[0][1]*a[1][0];
        }
        else if(size_m == 3)
        {
            return a[0][0]*a[1][1]*a[2][2] + a[2][0]*a[0][1]*a[1][2] + a[0][2]*a[1][0]*a[2][1]
                  -a[0][0]*a[2][1]*a[1][2] - a[2][2]*a[1][0]*a[0][1] - a[2][0]*a[1][1]*a[0][2]; 
        }
        else 
        {
            long long int det = 0;
            for(int cot=0 ; cot<size_m ; cot++)
            {
                int ro = _1pow(cot+2);
                //cout << i << ". pow : " << ro << endl;
                //cout << "+= " << ro*Det(BuDs(a,0,i)) << endl;
                det += ro*a[0][cot]*Det(BuDs(a,0,cot));
            }
            return det;
        }
    }
    return 0;
}

vector<int> GetRow(vvi matrix, int row)
{
    return matrix[row];
}
vector<int> GetCol(vvi matrix, int p_col)
{
    vector<int> col;
    for(vector<int> row : matrix)
    {
        col.push_back(row[p_col]);
    }
    return col;
}

long long int Dot_product(vector<int> u , vector<int> v)
{
    long long int proDuct =0;
    for(int i=0 ; i< u.size() ; i++)
        proDuct += u[i]*v[i];
    return proDuct;
}

vvi MultiMatrix(vvi A, vvi B)
{
    vvi C(A.size(), vector<int>(B[0].size()));
     
    for(int h = 0 ; h < A.size() ; h ++)
    {
        for(int c = 0 ; c < B[0].size() ; c++) C[h][c] = Dot_product(GetRow(A,h),GetCol(B,c));
    }
    return C;
}
int Count0f(vi d)
{
    int count = 0;
    for(int i : d)
    {
        if( i == 0 ) return count;
        else count++;
    }
    return count;
}
vvi Gauss(vvi a)
{
    if(a.size() <= 1) return a;
    for(int i = 1, j = 0; i<a.size() && j<a[0].size()-1 ; i++ , ++j)
    {
        int k = a[i][j] / a[i-1][j];
        for(int d = i ; d<a.size() ; d++)
        {
            for(int p = j ; p<a[0].size() ; p++)
            {
                a[d][p] = a[d][p] - k*a[i-1][d];
            }  
        }
        
    }
    return a;
}