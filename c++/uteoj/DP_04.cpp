#include<iostream>
#include<climits>
using namespace std;
int n,a[50001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int max_diff= 0;
    int min_val = INT_MAX;
    for(int i=1 ; i<=n ; i++)
    {
        cin >> a[i]; 
        if(i == 1) continue;
        // thuật toán Max Difference with Index Condition
        max_diff = max(max_diff , a[i] - min_val);
        min_val = min(min_val,a[i]);
    }
    
    cout << max_diff;
    return 0;
}
