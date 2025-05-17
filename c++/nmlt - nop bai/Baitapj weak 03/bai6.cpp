#include <iostream>
#include <string>
using namespace std;

bool checkSoChung(string a, string b)
{
    int count = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (a[i] == b[j])
                count++;
        }
    }

    return (count == 1);
}

int main()
{
    string a, b;
    cin >> a >> b;
    cout << checkSoChung(a, b);
    return 0;
}