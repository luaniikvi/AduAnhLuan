#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[1000];
    int len=0 , maxLen=0;
    for(int i=0 ; i<n ; i++) 
    {
        cin >> a[i];
        if(a[i] > 0)
        {
            len++;
            if(len > maxLen) maxLen = len;
        }
        else len =0;
    }

    cout << maxLen;
}