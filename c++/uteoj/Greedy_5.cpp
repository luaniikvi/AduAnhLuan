#include<iostream>
#include<vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,L,r;cin >> n >> L >> r;
    //n = 5 , L = 25 , r = 5;
    vector<int> a(n);
    for(auto &i : a) cin >> i;
    int end = a.back();
    int d = 2*r;
    int pos = a[1];
    int count = 1;
    for(int i = 1 ; i< n ; i++)
    {
        if(a[i] < pos + d) continue;
        else if(a[i] > pos + d)
        {
            pos = a[i];
            count++;
        }
        else{
            pos = a[i];
            if(i != n-1)
                count++;
            else break;
        }
    }
    
    cout << count;
    return 0;
}