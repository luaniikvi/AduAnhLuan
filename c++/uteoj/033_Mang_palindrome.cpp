#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[1000];
    for(int i=0 ; i<n ; i++) cin >> a[i];
    int left = 0,right = n-1;

    while(left<=right)
    {
        if(a[left]!= a[right]) 
        {
            cout << "NO";
            return 0;
        }
        left++;right--;
    }
    cout << "YES";
    return 0;
}