#include <iostream>
#include <set>

using namespace std;
int main()
{
    set<int> a;
    for (int i = 1; i < 31; i++)
        a.insert(i);
    for (int i = 0, in; i < 28; i++)
    {
        cin >> in;
        a.erase(in);
    }
    for(auto x : a) cout << x << ' ';
}