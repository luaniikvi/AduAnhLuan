#include <iostream>
using namespace std;

int ucln(int a, int b);
long long bcnn(int a, int b);

int main()
{
    int a, b;
    cin >> a >> b;
    cout << bcnn(a, b);

    return 0;
}

int ucln(int a, int b)
{
    while (a != b)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}
long long bcnn(int a, int b)
{
    if (a == 1)
        return b;
    if (b == 1)
        return a;
    return ((1LL * a * b) / (1LL * ucln(a, b)));
}