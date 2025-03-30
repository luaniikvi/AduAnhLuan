#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int UCLN(int a,int b)
{
    if(b == 0) return a;
    else return UCLN(b,a%b);
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &num : a) cin >> num;

    int max = *max_element(a.begin(),a.end());
    int min1 = *min_element(a.begin(),a.end());
    int min2 = max;
    for(int i=0 ; i<n ; i++)
    {
        if(a[i] == min1) continue;
        min2 = min(min2,a[i]);
    }

    cout << min1 << " " << min2 <<endl;

    cout << UCLN(min1,min2);
    return 0;
}