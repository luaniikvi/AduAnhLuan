#include<iostream>
//#include"matrix.h"
#include"matrix_1.0.1.h"
using namespace std;

int main()
{
    Matrix a1;
    cin >> a1;
    Matrix b = MultiMatrix(a1,a1);
    cout << "yeah" << endl;
    cout << b;
    return 0;
}