#include<iostream>
using namespace std;

void fill(long long int a[50][50], int n);

int main()
{   
    int n;
    cin >> n;
    long long int matrix[50][50];
    fill(matrix,n);

    for(int i= 0 ;i<n ; i++)
    {
        for(int j = 0 ; j<=i ; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void fill(long long int a[50][50], int n)
{
    for(int i= 0 ;i<n ; i++)
    {
        for(int j = 0 ; j<=i ; j++)
        {
            if(i == j || j == 0) a[i][j] = 1;
            else{
                a[i][j] = a[i-1][j] + a[i-1][j-1];
            }
        }
    }
}
