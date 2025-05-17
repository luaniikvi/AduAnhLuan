#include<iostream>
#include<vector>
#include"clss.cpp"
using namespace std;
typedef Bool cc;
int Fac(int n)
{
    if(n <= 1) return 1;
    return n*Fac(n-1);
}
void Print(vector<int> a)
{
    cout << '{';
    for(int i=0 ; i<a.size()-1; i++)
        cout << a[i] << ',';
    cout << a.back() << '}' << endl;
    return;
}
vector<int> HoanVi(vector<int> &a)
{
    int m=0;
    for(int i=0 ; i< a.size() -1;  i++)
        if(a[i] < a[i+1]) m = i;
    int k=0;
    for(int i=0 ; i< a.size();  i++)
        if(a[i] > a[m]) k = i;
    swap(a[k], a[m]);
    //cout << "m = " << m << " k = " << k << endl;
    int l = m+1;
    int r = a.size()-1;
    if(l >= r) return a;
    while(l < r){
        swap(a[l], a[r]);
        l++;r--;
    }
    return a;
}