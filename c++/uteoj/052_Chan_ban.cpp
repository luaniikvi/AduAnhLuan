#include<iostream>
#include<algorithm>
using namespace std;
string check(int a[4])
{
    if(a[1] - a[0] == a[3] - a[2]) return "YES";
    return "NO";
}
int main()
{
    int a[4];
    for(int &i : a) cin >> i;
    sort(a,a+3);

    cout << check(a);
}