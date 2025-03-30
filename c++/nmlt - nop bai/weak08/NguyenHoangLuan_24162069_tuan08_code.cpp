//041_Dãy nón
#include<iostream>
using namespace std;

bool check(int a[],int size);

int main()
{
    int n;
    cin >> n;
    int a[1000];
    for(int i = 0 ; i< n ; i++)
    {
        cin  >> a[i];
    }
    cout << (check(a,n) ? "YES" : "NO");
    return 0;
}

bool check(int a[],int size)
{
    bool tang,giam;
    if(size <=  2) return false;
    for(int i= 0 ; i<size ; i++)
    {
        tang =true;
        giam = true;
        for(int j= 0 ; j<i ;j++)
        {
            if(a[j] >= a[j+1]) tang = false;
        }
        for(int j= i+1 ; j<size ;j++)
        {
            if(a[j] >= a[j-1]) giam = false;
        }
        if(tang && giam) return true;
    }
    return false;
}

//047_Ma trận xoắn ốc
#include<iostream>
using namespace std;

void PrintMatrix(int m , int n);

int main()
{
    int m,n;
    cin >> m >> n;
    
    PrintMatrix(m,n);

    return 0;
}

void PrintMatrix(int m , int n)
{
    int matrix[100][100];
    int left = 0,right = n-1;
    int top = 0, bot = m-1;
    int num = 1;
    while(true)
    {
        // tren
        for(int i=left ; i<= right; i++)
        {
            matrix[top][i] = num;
            num++;
        }
        if(num > m*n) break;
        // phai
        for(int i=top+1 ; i<bot ; i++)
        {
            matrix[i][right] = num;
            num++;
        }
        if(num > m*n) break;

        // duoi
        for(int i=right ; i>=left ; i--)
        {
            matrix[bot][i] = num;
            num++;
        }
        if(num > m*n) break;

        // trai
        for(int i = bot-1 ; i>top ; i--)
        {
            matrix[i][left] = num;
            num++;
        }
        if(num > m*n) break;
        
        // tru size
        left++;right--;
        top++; bot--;

    }

    for(int i=0 ; i<m ; i++)
    {
        for(int j =0 ; j < n ; j++)
        {
            //cout.width(3);
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

//026_Chênh lệch liên tiếp
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int curr;
    int prev;
    int max = 0;
    for(int i =0 ; i<n ; i++)
    {
        cin >> curr;
        if(i == 0) prev = curr;
        else
        {
            if(abs(curr - prev) > max)
            {
                max = abs(curr - prev);
            }
            prev = curr;
        }
    }
    cout << max;
}

//035_Mảng con dương
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[1000];
    int len=0 , maxLen=0;
    for(int i=0 ; i<n ; i++) 
    {
        cin >> a[i];
        if(a[i] > 0)
        {
            len++;
            if(len > maxLen) maxLen = len;
        }
        else len =0;
    }

    cout << maxLen;

    return 0;
}

//030_Lớn thứ hai
#include<iostream>
#define INT_MIN -100000
using namespace std;
int main()
{
    int n;cin >> n;
    int a[1000];int max;int secMax = INT_MIN;
    for(int i =0; i<n ; i++)
    {
        cin >> a[i];
        if(i == 0) max = a[0];
        else if(a[i] > max) max = a[i];
    }
    for(int i =0 ; i<n ; i++)
    {
        if(a[i]==max) continue;
        if(a[i] > secMax) secMax = a[i];
    }
    if(secMax == INT_MIN) cout << "None";
    else cout << secMax;

    return 0;
}

//033_Mảng Palindrome
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

    for(int i=0 ; i<n ; i++){
        sum = max(a[i] , sum +a[i]);
        max_sum = max(sum,max_sum);
    }
    cout << max_sum;
    return 0;
}
//6_M1C_DemKoSNTLonX_GK2_09_10_3
#include<iostream>
using namespace std;
bool isPrime(int n)
{
    if(n<=1) return false;
    if(n<=3) return true;
    if(n%2==0 || n%3==0) return false;
    for(int i=5 ; i*i<=n ; i+=6){
        if(n%i == 0 || n%(i+2) == 0) return false;
    }
    return true;
}
int main()
{
    int n,x;
    cin >> n >> x;
    int a,count =0;

    for(int i =0 ; i< n ; i++)
    {
        cin >> a;
        if(!isPrime(a) && a > x) count++;
    }

    cout << count;
    return 0;
}
//7_MT_MaxDongGiua_CK1_13_14
#include<iostream>
using namespace std;
int main()
{
    int m,n;
    cin >> m >> n;
    int a[100][100];
    int max_num;
    for(int i=0 ; i< m ; i++)
    {
        for(int j=0 ; j<n ; j++) cin >> a[i][j];
    }

    for(int i=0 ; i<n ; i++)
    {
        if(i == 0) max_num = a[m/2][i];
        else max_num = max(max_num,a[m/2][i]);
    }

    cout << max_num;
    return 0;
}

//8_M1C_ChuTrinh_CK1_14_15
#include<iostream>
using namespace std;

int main(){
    int n,k,a[100],b[100];
    cin >> n >> k;

    for(int i = 0 ; i<n ;i++) cin >> a[i];

    if(a[0] != a[n-1]) cout << -1;
    else
    {
        for(int i=k ; i<k+n ; i++)
        {
            if(i >= n) cout << a[i-(n-1)] << " ";
            else cout << a[i] << " ";
        }
    }

    return 0;
}