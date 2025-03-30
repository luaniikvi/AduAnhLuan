#include<iostream>
#include<vector>
using namespace std;
long minRefuelStops(long n, long l, long C, vector<long>& a) {
    long currentPos = 0;
    long stops = 0;
    long i = 0;

    while (currentPos < l) {
        long farthest = currentPos;
        // Tìm trạm xa nhất có thể đến từ currentPos
        while (i < n && a[i] - currentPos <= C) {
            farthest = a[i];
            i++;
        }

        currentPos = farthest;
        if (currentPos < l) {
            stops++;
        }
    }

    return stops;
}
int main()
{
    long n,l,full_c;
    cin >> n >> l >> full_c;

    vector<long> a(n);
    for(auto &i : a) cin >> i;

    
    cout << minRefuelStops(n,l,full_c,a);
    return 0;
}