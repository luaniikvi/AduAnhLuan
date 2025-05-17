#include<iostream>
using namespace std;
int BCNN(int a,int b);
int main()
{
    double a,b;
    cin >> a >> b;
    int x,y;
    x = static_cast<int>(a);
    y = static_cast<int>(b);

    cout << BCNN(x,y);

    return 0;
}

int UCLN(int a,int b)
{
    while(b!= 0)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }

    return a;
}


int BCNN(int a,int b)
{
    return ( a / UCLN(a,b)) * b;
}