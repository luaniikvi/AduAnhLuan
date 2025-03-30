#include<iostream>
using namespace std;

string GetPrefix(string a, string b)
{
    if(b.length() <= a.length()) swap(a,b);
    if(a == b) return a;
    b.pop_back();
    return GetPrefix(a,b);
}

int main()
{
    int n;
    cin >> n;

    string prefix = "";
    cin >> prefix;

    for(int i=1 ; i<n ; i++)
    {
        string text;
        cin >> text;
        prefix = GetPrefix(prefix,text);
    }
    cout << prefix;
    return 0;
}