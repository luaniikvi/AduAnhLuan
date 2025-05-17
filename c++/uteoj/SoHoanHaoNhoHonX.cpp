#include<iostream>
#include<vector>
#include<climits>
using namespace std;
bool isPerf(int n)
{
    if(n <= 1) return  false;
    int sum =1;
    for(int i= 2; i < n ; i++)
    {
        if(n%i == 0) sum += i;
    }

    return sum == n;
}
                //1;
int main()
{
    int n,x;cin >> n >> x;
    
    vector<int> a(n);
    for(int &num : a) cin >> num;
    
    int maxNum = INT_MIN;
    for(int i=0 ; i<n ; i++)
    {
        if(a[i] >= x) continue;
        if(isPerf(a[i])) maxNum = max(maxNum,a[i]);
    }

    cout << (maxNum == INT_MIN ? 0 : maxNum);
}
