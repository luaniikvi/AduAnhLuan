#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct A{
    int s,b,r;
};
int main()
{
    int n;
    vector<A> a(n);
    long long t1= 0;
    for(auto &i : a)
    {
        cin >> i.s >> i.b >> i.r;
        t1 += i.s;
    }
    cout << t1 + max(a.back().b,a.back().r);

    return 0;
}