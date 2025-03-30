#include<iostream>
using namespace std;

bool check(int a[],int size);

int main()
{
    int n;
    cin >> n;
    int a[1000];
    for(int i = 0 ; i< n ; i++)
    {
        cin  >> a[i];
    }
    cout << (check(a,n) ? "YES" : "NO");
    return 0;
}

bool check(int a[],int size)
{
    bool tang,giam;
    if(size <=  2) return false;
    for(int i= 0 ; i<size ; i++)
    {
        tang =true;
        giam = true;
        for(int j= 0 ; j<i ;j++)
        {
            if(a[j] >= a[j+1]) tang = false;
        }
        for(int j= i+1 ; j<size ;j++)
        {
            if(a[j] >= a[j-1]) giam = false;
        }
        if(tang && giam) return true;
    }
    return false;
}