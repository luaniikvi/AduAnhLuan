#include<iostream>
#include<vector>
#define vvi vector<vector<int>>
#define vi vector<int>
using namespace std;

int F(vvi a , int i0 , int j0)
{
    int h = a.size();
    int c = a[0].size();
    if(i0 <0) i0 +=2;
    else if(i0>=h) i0-=2;
    if(j0 <0) j0 +=2;
    else if(j0>=c) j0-=2;
    return a[i0][j0];
}
int main()
{
    int m,n;
    cin >> m >> n;
    vvi a(m,vi(n));
    for(vi& d : a)
    for(int &i : d) cin >> i;
    long long tong = 0;


    for(int i=  0 ; i<m ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            int num = a[i][j];
            if(num > F(a,i,j+1) && num > F(a,i+1,j)
            && num > F(a,i-1,j) && num > F(a,i,j-1))
            {
                tong+=num;
            }
            if(num < F(a,i,j+1) && num < F(a,i+1,j)
            && num < F(a,i-1,j) && num < F(a,i,j-1))
            {
                tong+=num;
            }
        }
    }


    cout << tong;
 }