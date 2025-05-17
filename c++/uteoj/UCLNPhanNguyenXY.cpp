#include<iostream>
using namespace std;

int UCLN(int a, int b);

int main()
{
    double x,y;
    cin >> x >> y;

    cout << UCLN(static_cast<int>(x),static_cast<int>(y));

    return 0;
}

int UCLN(int a, int b)
{
    int temp = a % b;
    while(temp != 0)
    {
        a =b;
        b = temp;
        temp = a % b;
    }

    return b;
}