#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> Rotate(vector<vector<int>> matrix,int n);


int main()
{
    int n;
    cin >> n;

    vector<vector<int>> matrix(n,vector<int>(n));
    for(vector<int> &hang : matrix)
    {
        for(int &ptu : hang)
        {
            cin >> ptu;
        }
    }

    vector<vector<int>> after_rotate;
    after_rotate = Rotate(matrix,n);

    for(vector<int> &hang : after_rotate)
    {
        for(int &ptu : hang)
        {
            cout << ptu << " ";
        }
        cout << endl;
    }

    return 0;
}

vector<vector<int>> Rotate(vector<vector<int>> matrix , int n)
{
    vector<vector<int>> rotate;
    vector<int> temp;
    
    for(int c=0; c<n ;c++)
    {
        for(int h=n-1 ; h>=0 ; h--)
        {
            temp.push_back(matrix[h][c]);
        }
        rotate.push_back(temp);
        temp.clear();
    }
    return rotate;
}