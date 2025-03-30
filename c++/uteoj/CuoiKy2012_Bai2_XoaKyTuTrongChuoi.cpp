#include<iostream>
using namespace std;

string Simplize(string s);

int main()
{
    string s;
    getline(cin , s);
    cout << Simplize(s);

    return 0;
}

string Simplize(string s)
{
    string simple = "";
    for(int i=0;i<s.length();i++)
    {
        if(s[i] == 'A') continue;
        if(s[i] == 'E') continue;
        if(s[i] == 'I') continue;
        if(s[i] == 'O') continue;
        if(s[i] == 'U') continue;
        simple+=s[i];
    }
    return simple;
}