#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

void printTheSecLargest(vector<int> a);

int main()
{
    [=]()
    {
        ios_base::sync_with_stdio(NULL);
        cout.tie(NULL);
    }();
    int n;
    //cout << "Nhap vao kich thuoc cua day: ";
    cin >> n;
    //cout << "Nhap vao cac so cua day: ";
    vector<int> a(n);
    for(int i=0; i <n;i++)
    {
        cin >> a[i];
    }

    printTheSecLargest(a);

    return 0;
}

void printTheSecLargest(vector<int> a)
{
    int max1=*max_element(a.begin(),a.end());
    int max2=INT_MIN;
    for(int num : a)
    {
        if(num == max1) continue;
        if(num > max2) max2 = num;
    }    
    if(max2!=INT_MIN){
        //cout << "So can lon nhat: ";
        cout << max2;
    }
}
