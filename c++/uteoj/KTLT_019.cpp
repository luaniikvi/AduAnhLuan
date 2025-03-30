#include<iostream>
using namespace std;

string test(int a,int b,int c)
{
    if(a+b == c) return "Possible";
    if(a+c == b) return "Possible";
    if(b+c == a) return "Possible";
    if(a*b == c) return "Possible";
    if(a*c == b) return "Possible";
    if(c*b == a) return "Possible";
    
    return "Impossible";
}

int main()
{
    int n;
    cin >> n;
    for(int i=0 ; i<n; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        cout << test(a,b,c) << endl;
    }
    return 0;
}   