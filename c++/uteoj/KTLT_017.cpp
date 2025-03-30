#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    string a,b;
    getline(cin , a);
    getline(cin , b);

    if(a.length() > b.length()) swap(a,b);
    int maxLen = 0;
    
    cout << maxLen;
    return 0;
}