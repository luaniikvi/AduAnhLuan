#include<iostream>
#include<cmath>
using namespace std;

double DELTA(double a, double b, double c)
{
    return (b*b - 4*a*c);
}

int main()
{
    double a,b,c;
    cin >> a >> b >> c;
    if(a == 0 && b == 0 && c == 0)
    {
        cout << 4;
        return 0;
    }
    else if(a == 0 && c!= 0)
    {
        cout << 1;
        return 0;
    }
    double del = DELTA(a,b,c);
    if(del < 0) cout << 0;
    else if(del == 0) cout << 3;
    else if(del > 0) cout << 2;

}