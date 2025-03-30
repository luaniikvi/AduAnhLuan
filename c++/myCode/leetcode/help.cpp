#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[100];long long tich = 1;int dem_so_0 = 0;

    for(int i=0 ; i<n ; i++)
    {
        cin >> a[i];
        tich *= a[i];
    }
    while(tich>0){
        if(tich%10 == 0){
            tich = tich /10;
            dem_so_0++;
        }
        else break;// đến khi không còn chia hết 10 thì thoát vòng lập
    }
    cout << dem_so_0 << endl;

    return 0;
}