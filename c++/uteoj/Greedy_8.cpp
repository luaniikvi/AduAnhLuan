#include <iostream>
#include <vector>
using namespace std;

long maxtime ,total_bit;
struct Greedy_8
{
    long b, t;
};

int main()
{
    long n, r;
    cin >> n >> r;
    vector<Greedy_8> a(n);
    for (auto &i : a)
    {
        cin >> i.b >> i.t;
        total_bit += i.b;
        maxtime+= i.t;
    }
        
    cout << (total_bit <= r*maxtime ? "YES" : "NO");
}