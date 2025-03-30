#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int SumMatrix(vector<vector<int>> matrix , int m , int n , int k);

int main()
{
    [=]()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }();

    int n , k;
    cin >> n >> k;

    vector<vector<int>> matrix(n,vector<int>(n));
    int sum =0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> matrix[i][j];
            sum += matrix[i][j];
        }
    }
    if(n == k)
    {
        cout << sum;
        return 0;
    }
    else
    {
        int m = INT_MIN;
        for(int i=0 ; i<n+1-k ; i++)
        {
            for(int j=0 ; j<n+1-k ; j++)
            {       
                m = max(m,SumMatrix(matrix,i,j,k));
            }
        }
        cout << m;
    }

    return 0;
}

int SumMatrix(vector<vector<int>> matrix , int m , int n , int k)
{
    int sum =0;
    for(int i=m ; i<m+k ; i++)
    {
        for(int j =n ; j<n+k ; j++)
        {
            sum+=matrix[i][j];
        }
    }

    return sum;
}