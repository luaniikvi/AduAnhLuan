#include<iostream>
using namespace std;

int DemTu(string s);

int main()
{
    string s;
    getline(cin,s);
    cout << DemTu(s);
}

bool isChu(char c)
{
    return ( (c>='a' && c<='z') || (c>='A' && c<='Z'));
}

int DemTu(string s)
{
    int count = 0;
    while(s[0]==' ')
    {
        s.erase(s.begin(),s.begin()+1);
    }
    while(s.back() == ' ')
    {
        s.pop_back();
    }
    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == ' ' && isChu(s[i-1])) count++;
    }

    return (count+1);
}