#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int> a)
{
    for (int i = a.size() - 1; i >= 0; i--)
    {
        if (a[i] < 9)
        {
            a[i]++;
            return a;
        }

        a[i] = 0;
    }
    a.insert(a.begin(), 1);
    return a;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &i : a) cin >> i;

    for(int i : plusOne(a))
    {
        cout << i;
    }
}