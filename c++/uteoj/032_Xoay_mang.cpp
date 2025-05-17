#include<iostream>
#include<vector>
using namespace std;

void DuaDauXuongDich(vector<int> &a);

int main()
{
    int n,k; cin >> n >> k;
    vector<int> a(n);
    for(int &n : a) cin >> n;

    for(int i=0 ; i< k; i++)
    {
        DuaDauXuongDich(a);
    }
    for(int &n : a) cout << n << " ";

}

void DuaDauXuongDich(vector<int> &a)
{
    int dau = a[0];
    for(int i=0 ; i<a.size()-1;i++)
    {
        a[i] = a[i+1];
    }
    a[a.size()-1] = dau;
}
