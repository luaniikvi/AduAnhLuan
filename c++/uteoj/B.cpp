#include<iostream>
using namespace std;
int main()
{
    int n;
    string a,b;
    cin >> n;
    for(int d= 0 ; d< n ; d ++)
    { 
        cin >> a >> b;

        for(int i=0 ; i<a.length() ; i++)
        {
            for(int j = 0 ; j<a.length()-1 ; j++)
            {
                if(a[j] > a[j+1]) swap(a[j],a[j+1]);
            }
        }
        for(int i=0 ; i<b.length() ; i++)
        {
            for(int j = 0 ; j<b.length()-1 ; j++)
            {
                if(b[j] > b[j+1]) swap(b[j],b[j+1]);
            }
        }
        if(a == b) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
}