#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for(int i=0; i<n ;i++)
    {
        cin >> a[i];
    }
    cout << *max_element(a.begin(),a.end()) << " " << *min_element(a.begin(),a.end());

    return 0;
}