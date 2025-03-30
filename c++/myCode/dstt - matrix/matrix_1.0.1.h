#include <iostream> 
#include <vector>
#include <sstream>
#include <conio.h>
#include "MyMatrixType.h"
using namespace std;

void PrintMatrix(const vvi A)
{
    Matrix a(A);
    cout << a;
}
void PrintMatrix(Matrix a)
{
    cout << a;
}
void PauseKeyboard()
{
    cout << "Press ANYTHING to continue...";
    _getch();
}
vvi CopyMatrix(char chooseMatrix, vvi A, vvi B, vvi C, vvi D)
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
    return vvi(0, vector<int>(0));
}
Matrix CopyMatrix(char chooseMatrix, Matrix A, Matrix B, Matrix C, Matrix D)
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
    return vvi(0, vector<int>(0));
}
string GetSize(char choose, vvi a, vvi b, vvi c, vvi d)
{
    vvi matrix = CopyMatrix(choose, a, b, c, d);
    string size = "(";
    size += IntToStr(matrix.size());
    size += 'x';
    size += IntToStr(matrix[0].size());
    size += ')';
    return size;
}
int _1pow(int n)
{
    if (n % 2 == 0)
        return 1;
    return -1;
}
// phan bu ds
vvi Algebraic_complement(vvi a, int i, int j)
{
    vvi vt;
    int size = a.size();
    vector<int> tempC;
    for (int h = 0; h < size; h++)
    {
        if (h == i)
            continue;
        for (int c = 0; c < size; c++)
        {
            if (c == j)
                continue;
            tempC.push_back(a[h][c]);
        }
        vt.push_back(tempC);
        tempC.clear();
    }
    return vt;
}

vvi BuDs(vvi a, int i, int j)
{
    return Algebraic_complement(a, i, j);
}

long long Det(vvi a)
{
    if (a.empty())
        return 0;

    int size_m = a.size();
    int size_n = a[0].size();

    if (size_m != size_n)
        return 0;
    else
    {
        if (size_m == 1)
        {
            return a[0][0];
        }
        else if (size_m == 2)
        {
            return a[0][0] * a[1][1] - a[0][1] * a[1][0];
        }
        else if (size_m == 3)
        {
            return a[0][0] * a[1][1] * a[2][2] + a[2][0] * a[0][1] * a[1][2] + a[0][2] * a[1][0] * a[2][1] - a[0][0] * a[2][1] * a[1][2] - a[2][2] * a[1][0] * a[0][1] - a[2][0] * a[1][1] * a[0][2];
        }
        else
        {
            long long int det = 0;
            for (int cot = 0; cot < size_m; cot++)
            {
                int ro = _1pow(cot + 2);
                // cout << i << ". pow : " << ro << endl;
                // cout << "+= " << ro*Det(BuDs(a,0,i)) << endl;
                det += ro * a[0][cot] * Det(BuDs(a, 0, cot));
            }
            return det;
        }
    }
    return 0;
}
long long Det(Matrix a)
{
    return Det(a.value);
}

vector<int> GetRow(vvi matrix, int row)
{
    return matrix[row];
}
vector<int> GetRow(Matrix matrix, int row)
{
    return matrix.value[row];
}
vector<int> GetCol(vvi matrix, int p_col)
{
    vector<int> col;
    for (vector<int> row : matrix)
    {
        col.push_back(row[p_col]);
    }
    return col;
}
vector<int> GetCol(Matrix matrix , int p_col)
{
    return GetCol(matrix.value, p_col);
}

long long int Dot_product(vi u, vi v)
{
    long long int proDuct = 0;
    for (int i = 0; i < u.size(); i++)
        proDuct += u[i] * v[i];
    return proDuct;
}

vvi MultiMatrix(vvi A, vvi B)
{
    vvi C(A.size(), vector<int>(B[0].size()));

    for (int h = 0; h < A.size(); h++)
    {
        for (int c = 0; c < B[0].size(); c++)
            C[h][c] = Dot_product(GetRow(A, h), GetCol(B, c));
    }
    return C;
}
Matrix MultiMatrix(Matrix A, Matrix B)
{
    Matrix C;
    C = MultiMatrix(A.value , B.value);
    return C;
}