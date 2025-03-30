#include<iostream>
using namespace std;

void PrintMatrix(int m , int n);

int main()
{
    int m,n;
    cin >> m >> n;
    
    PrintMatrix(m,n);

    return 0;
}

void PrintMatrix(int m , int n)
{
    int matrix[100][100];
    int left = 0,right = n-1;
    int top = 0, bot = m-1;
    int num = 1;
    while(true)
    {
        // tren
        for(int i=left ; i<= right; i++)
        {
            matrix[top][i] = num;
            num++;
        }
        if(num > m*n) break;
        // phai
        for(int i=top+1 ; i<bot ; i++)
        {
            matrix[i][right] = num;
            num++;
        }
        if(num > m*n) break;

        // duoi
        for(int i=right ; i>=left ; i--)
        {
            matrix[bot][i] = num;
            num++;
        }
        if(num > m*n) break;

        // trai
        for(int i = bot-1 ; i>top ; i--)
        {
            matrix[i][left] = num;
            num++;
        }
        if(num > m*n) break;
        
        // tru size
        left++;right--;
        top++; bot--;

    }

    for(int i=0 ; i<m ; i++)
    {
        for(int j =0 ; j < n ; j++)
        {
            //cout.width(3);
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
