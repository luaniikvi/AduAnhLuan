//MT1-Array1D-2022-11-24-Bai5
#include<iostream>

int main(){
    int n;
    std::cin >> n;
    int MyArr[100];
    int count = 0;

    for(int i = 0 ; i<n ; i++){
        std::cin >> MyArr[i];
    }

    for(int j = 1 ; j < n; j++){
        if(MyArr[j] == MyArr[j-1] && MyArr[j] != MyArr[j+1] ){
            count++;
        }

    }
    std::cout << count;

    return 0;
}

//MT1-Array1D-202211-24-Bai4
#include<iostream>
using namespace std;
int main()
{
    int input,size,dem2=0,dem5=0;
    cin >> size;
    for(int i=0 ; i<size ; i++)
    {
        cin >> input;
        if(input == 0) continue;
        while (input %2 ==0)        
        {
            input/=2;
            dem2++;
        }
        while (input %5 ==0)        
        {
            input/=5;
            dem5++;
        }
    }

    cout << min(dem2,dem5);
    return 0;
}
//MT1-Array1D-2022-11-24-Bai3
#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int n,a[100];
    cin >> n;
    for(int i=0 ;i<n; i++) cin >> a[i];

    long long _max = INT_MIN;
    for(int i=0 ; i<n-1 ; i++)
    {
        for(int j= i+1 ;j<n ; j++)
        {
            if(a[i] == a[j]) continue;
            _max = max(_max , 1LL*a[i]*a[j]);
        }
    }
    cout << (_max == INT_MIN ? 0 : _max);
}
//MT1-Array1D-2022-11-24-Bai2
#include<iostream>
#define ll long long
using namespace std;
int main()
{
    int size;
    cin >> size;
    ll arr[100];
    ll sum = 0;
    for(int i=0; i<size ;i++){
        cin >> arr[i];
        sum+= arr[i];
    }

    int pos = -1;
    ll tong_phu =0;

    for(int vachNgan = 0 ; vachNgan<size-1 ; vachNgan ++){
        for(int i=0 ; i<=vachNgan ; i++){
            tong_phu+=arr[i];
        }
        if(tong_phu == sum - tong_phu){
            pos = vachNgan;
            break;
        }
        tong_phu =0;
    }

    cout << pos;


    return 0;
}
//MT1-Array1D-202211-24-Bai1
#include<iostream>
#include<cmath>
using namespace std;
int main(){

    int size;cin >> size;
    int arr[100];

    for(int i=0;i<size;i++){
        cin >> arr[i];
    }
    int _min = 1e6;
    for(int i=1 ; i<size ;i++)
    {
        _min = min(_min , abs(arr[i]-arr[i-1]));
    }
    cout << _min;
    return 0;
}
//MT1-Array1D-2022-11-21-Bai5
#include<iostream>
using namespace std;
int main(){
    int n;cin>>n;
    int a[100];

    for(int i=0; i<n ; i++){
        cin>>a[i];
    }
    int sum=a[0];
    int max_sum=a[0];

    for(int i=1 ; i<n ; i++){
        sum = max(a[i] , sum +a[i]);
        max_sum = max(sum,max_sum);
    }
    cout << max_sum;
    return 0;
}
//MT1-Array1D-2022-11-21-Bai4
#include<iostream>
using namespace std;

int main(){
    int n;
    int a[100];
    int pos =-1;
    cin >> n;
    for(int i=0 ;i<n;i++){
        cin >> a[i];
    }

    for(int i=0 ;i<n ; i++){
        for(int k = i+1 ; k<n ; k++){
            if(a[i] == a[k]){
                pos = i;
                i = n;
                break;
            }
        }
    }
    cout << pos;

    return 0;
}
//MT1-Array1D-2022-11-21-Bai3\
#include<iostream>
#include<climits>
using namespace std;
int ttd(int n);
void findPos(int a[], int n,int input){
    int min = INT_MAX;
    for(int i=0 ; i<n ; i++){
        if( ttd(a[i] - input) < min){
            if(ttd(a[i] - input) == 0) continue;
            min = ttd(a[i] - input);
        }
        else continue;
    }
    for(int i =0 ; i<n ; i++){
        if ( ttd(a[i]-input) == min){
            cout << i;
            break;
        }
        else continue;
    }
}

int main(){
    int n;
    cin >> n;
    int input;
    cin >> input;
    int a[100];
    for(int i=0; i<n ; i++){
        cin >> a[i];
    }
    findPos(a,n,input);
    return 0;
}

int ttd(int n){
    if(n <0) n =-n;
    return n;
}
//MT1-Array1D-2022-11-21-Bai2
#include<iostream>
using namespace std;
int main()
{
    int n;cin >> n;
    int a[100],first_max = -1e6,sec_max = -1e6;
    for(int i= 0 ;i < n ;i++) cin >> a[i];
    for(int i= 0 ;i < n ;i++)
    {
        first_max = max(first_max,a[i]);
    }
    for(int i= 0 ;i < n ;i++)
    {
        if(first_max == a[i]) continue;
        sec_max = max(sec_max , a[i]);
    }
    cout << (sec_max == -1e6 ? -1 : sec_max);
}
//MT1-Array1D-2022-11-21-Bai1
#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[100];
    int fpos = -1, epos = -1;
    for(int i=0 ; i<n ; i++) cin >> a[i];
    int _max = a[0];
    for(int i=1 ; i<n ; i++) _max = max(_max,a[i]);
    for(int i=0 ; i<n ; i++)
    {
        if(a[i] == _max){fpos = i ; break;}
    }
    for(int i=0 ; i<n ; i++)
    {
        if(a[i] == _max) epos = i;
    }
    cout << (epos - fpos);
}