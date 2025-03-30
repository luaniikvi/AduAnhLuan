#include<iostream>
#include<vector>
#include<cmath>
using namespace std; 
bool isPerf(int n);
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int count = 0;
    for(int &num : a)
    {
        cin >> num;
        if(isPerf)
        {
            count++;
        }
    }

    long double total;
    if( count == 0)
    {
        cout << 0;
        return 0;
    }
    for(int &n : a)
    {
        if(isPerf(n))
        {
            total += (double) n / count;
        }
    }
    cout << round(total);
    
    return 0;
}

bool isPerf(int n) // 6  28 496 8128
{
    return (n == 6 || n == 28 || n == 496 || n == 8128);
}
