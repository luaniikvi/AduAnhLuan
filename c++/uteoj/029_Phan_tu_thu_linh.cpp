#include<iostream>
using namespace std;

int DemThuLinh(int a[1000],int size);


int main()
{
    int n; cin>>n;
    int a[1000];
    for(int i=0 ; i<n ; i++) cin >> a[i];

    cout << DemThuLinh(a,n); 

    return 0;
}

bool isThuLinh(int a[1000], int pos,int size)
{
    if(pos == size-1 ) return false;
    for(int i = pos+1 ; i<size ; i++)
    {
        if(a[pos]  <= a[i]) return false;
    }
    return true;
}

int DemThuLinh(int a[1000],int size)
{
    int count =0;
    for(int i=0 ; i<size-1 ; i++)
    {
        if(isThuLinh(a,i,size))
        {
            count++;
        }
    }
    return count;
}

