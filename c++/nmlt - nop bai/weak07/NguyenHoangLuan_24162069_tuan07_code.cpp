//037_Mảng giống nhau
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[1000];
    int b[1000];

    for(int i=0 ; i<n ; i++) cin >> a[i];
    for(int j=0 ; j<n ; j++) cin >> b[j];

    for(int j=0 ; j<n ; j++)
    {
        for(int i = 0 ; i < n -1 - j ; i ++)
        {
            if(a[i] > a[i+1]) swap(a[i] , a[i+1]);
            if(b[i] > b[i+1]) swap(b[i] , b[i+1]);
        }
    }

    bool equal = true;
    for(int i=0 ; i< n ; i++)
    {
        if(a[i]!= b[i])
        {
            equal = false;
            break;
        }
    }

    cout << (equal ? "YES" : "NO");

    return 0;
}

//038_Độc nhất
#include<iostream>
using namespace std;
int  main()
{   
    int n;
    cin >> n;
    int a[1000];
    int b[1000];
    int b_size = 0;

    bool check;

    for(int i=0 ;i < n ; i++)
    {
        cin >> a[i];
        if(i == 0) check == false;
        else 
        {
            for(int j=0 ; j<b_size; j++)
            {
                if(a[i] == b[j])
                {
                    check = true;
                    break;
                }
                check = false;
            }
        }
        if(!check)
        {
            b[b_size] = a[i];
            b_size++;
        }
    }

    for(int i= 0 ; i<b_size ; i++)
    {
        for(int j = 0 ; j<b_size-1-i ; j++)
        {
            if(b[j] > b[j+1]) swap(b[j],b[j+1]);
        }
    } 

    for(int i= 0 ; i<b_size ; i++)
    {
        cout << b[i] << " ";
    }
    

    return 0;
}

//039_Giá trị thường xuyên
#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int input;
    unordered_map<int,int> frequent;
    for(int i=0 ; i<n ;i++)
    {
        cin >> input;
        frequent[input]++; 
    }

    int dem =0;
    for(auto &_pair : frequent)
    {
        if(_pair.second > 2) dem++;
    }

    cout << dem;


    return 0;
}
//040_Giá trị xuất hiện nhiều nhất
#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
    int n,input;
    cin >> n;
    unordered_map<int,int> frequent;
    for(int i=0 ; i<n ; i++)
    {
        cin >> input;
        frequent[input] ++;
    }

    int maxF = 0;
    int SpecNum = 0;
    for(auto &_pair : frequent)
    {
        if(_pair.second > maxF)
        {
            maxF = _pair.second;
            SpecNum = _pair.first;
        }
        else if(_pair.second == maxF)
        {
            if(_pair.first > SpecNum)
            {
                SpecNum = _pair.first;
            }
        }
    }

    cout << SpecNum;
    return 0;
}

//043_Tổng cột
#include<iostream>
using namespace std;
int main()
{
    int m,n;
    cin >> m >> n;
    long long a[100][100];

    for(int i= 0 ;i < m ; i++)
    {
        for(int j= 0 ; j < n ; j++)
        {
            cin >> a[i][j];
        }
    }

    long long int sum = 0;
    for(int c = 0 ; c < n ; c++)
    {
        for(int h = 0 ; h< m ; h ++)
        {
            sum += a[h][c];
        }
        cout << sum << " ";
        sum = 0;
    }

    return 0;
}
//044_Hiện diện
#include<iostream>
#include<vector>
using namespace std;

bool check(vector<vector<int>>a,vector<vector<int>> b);

int main()
{
    int m,n,x,y;
    cin >> m >> n >> x >> y;

    vector<vector<int>> a(m,vector<int>(n));
    vector<vector<int>> b(x,vector<int>(y));
    
    for(vector<int> &i : a)
    {
        for(int &j : i) cin >> j;
    }
    for(vector<int> &i : b)
    {
        for(int &j : i) cin >> j;
    }
    
    cout << (check(a,b) ? "YES":"NO" ); 

    return 0;
}


bool equal(vector<vector<int>>a,vector<vector<int>> b,int i0, int j0)
{
    int mb = b.size();
    int nb = b[0].size();
    for(int i=i0 ; i<i0+mb ; i++)
    {
        for(int j=j0 ; j<j0+nb; j++)
        {
            if(a[i][j] != b[i-i0][j-j0])
            {
                return false;
            }
        }
    }

    return true;
}

bool check(vector<vector<int>>  a,vector<vector<int>> b)
{
    int ma = a.size();
    int na = a[0].size();
    int mb = b.size();
    int nb = b[0].size();
    for(int i = 0 ; i<=(ma - mb) ; i++)
    {
        for(int j=0 ;j<=(na - nb);j++)
        {
            if(a[i][j] == b[0][0])
            {
                if(equal(a,b,i,j)){
                    return true;
                }
            }
        }
    }

    return false;
}
//045_Tổng đường chéo
#include<iostream>
using namespace std;

int main()
{
    int m,n,x,y;
    cin >> m >> n >> x >> y;
    x--;y--;
    
    int a[100][100];

    for(int i= 0 ;i < m ; i++)
    {
        for(int j = 0; j < n ; j++)
        {
            cin >> a[i][j];
        }
    }

    long long total = a[x][y];
    int orix = x;
    int oriy = y;
    while(true)
    {
        x--;
        y--;
        if(x==-1 || y ==-1) break;
        total += a[x][y];
    }
    x = orix;
    y = oriy;
    while(true)
    {
        x--;
        y++;
        if(x==-1 || y == n) break;
        total += a[x][y];
    }
    x = orix;
    y = oriy;
    while(true)
    {
        x++;
        y++;
        if(x==m || y ==n) break;
        total += a[x][y];
    }
    x = orix;
    y = oriy;
    while(true)
    {
        x++;
        y--;
        if(x==m || y ==-1) break;
        total += a[x][y];
    }

    cout << total;

    return 0;
}
//048_Xoay ma trận
#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> Rotate(vector<vector<int>> matrix,int n);


int main()
{
    int n;
    cin >> n;

    vector<vector<int>> matrix(n,vector<int>(n));
    for(vector<int> &hang : matrix)
    {
        for(int &ptu : hang)
        {
            cin >> ptu;
        }
    }

    vector<vector<int>> after_rotate;
    after_rotate = Rotate(matrix,n);

    for(vector<int> &hang : after_rotate)
    {
        for(int &ptu : hang)
        {
            cout << ptu << " ";
        }
        cout << endl;
    }

    return 0;
}

vector<vector<int>> Rotate(vector<vector<int>> matrix , int n)
{
    vector<vector<int>> rotate;
    vector<int> temp;
    
    for(int c=0; c<n ;c++)
    {
        for(int h=n-1 ; h>=0 ; h--)
        {
            temp.push_back(matrix[h][c]);
        }
        rotate.push_back(temp);
        temp.clear();
    }
    return rotate;
}
//049_Tìm kiếm trong mảng
#include<iostream>
using namespace std;

int main()
{
    int n,x;
    cin >> n >> x;

    int a[1000];
    for(int i=0; i<n;i++)
    {
        cin >> a[i];
    }
    for(int i=0; i<n;i++)
    {
        if(a[i] == x)
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";

    return 0;
}
//050_Học đếm trong mảng
#include<iostream>
using namespace std;
int Count(int a[], int size, int target);

int main()
{
    int n,x;
    cin >> n >> x;
    int a[1000];
    for(int i=0 ; i<n ;i++)
    {
        cin >> a[i];
    }

    cout << Count(a,n,x);

    return 0;
}

int Count(int a[], int size, int target)
{
    int count = 0;
    for(int i=0 ; i<size ; i++)
    {
        if(a[i]==target) count++;
    }

    return count;
}