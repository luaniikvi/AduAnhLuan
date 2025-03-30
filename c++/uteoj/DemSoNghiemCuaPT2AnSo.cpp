#include<iostream>
using namespace std;

int findK(int a, int b, int c);

int main()
{
    int a,b,c;
    cin >> a >> b >> c;

    cout << findK(a,b,c);

    return 0;
}

int findK(int a, int b, int c)
{
    int k = 0;
    for(int x = 1 ; a*x < c ; x++)
    {
        double y = (double) (c - a*x) / b;
        if(y<0)
        if(y == static_cast<int>(y)) k++;
    }
    
    return k;
}