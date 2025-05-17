#include <iostream>
#include <math.h>
#include <iomanip> // fixed
#define tr 1e6
using namespace std;

long double tinhThue(long long s)
{
    if (s <= 5 * tr)
    {
        return s * 0.05;
    }
    else if (s <= 10 * tr)
    {
        return 0.25 * tr + (s - 5 * tr) * 0.1;
    }
    else if (s <= 18 * tr)
    {
        return 0.25 * tr + 5 * tr * 0.1 + (s - 10 * tr) * 0.15;
    }
    else if (s <= 32 * tr)
    {
        return 0.25 * tr + 5 * tr * 0.1 + 8 * tr * 0.15 + (s - 18 * tr) * 0.2;
    }
    else if (s <= 52 * tr)
    {
        return 0.25 * tr + 5 * tr * 0.1 + 8 * tr * 0.15 + 14 * tr * 0.2 + (s - 32 * tr) * 0.25;
    }
    else if (s <= 80 * tr)
    {
        return 0.25 * tr + 5 * tr * 0.1 + 8 * tr * 0.15 + 14 * tr * 0.2 + 20 * tr * 0.25 + (s - 52 * tr) * 0.3;
    }
    else
        return 0.25 * tr + 5 * tr * 0.1 + 8 * tr * 0.15 + 14 * tr * 0.2 + 20 * tr * 0.25 + (80 - 52) * tr * 0.3 + (s - 80 * tr) * 0.35;
}

int main()
{
    long long salary;
    cin >> salary;

    cout << fixed << setprecision(0) << tinhThue(salary) * 12;

    return 0;
}