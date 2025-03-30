// một số function thường dùng trong lập trình c++
    max(a,b) // trả về giá trị lớn nhất của a và b
    min(a,b) // trả về giá trị nhỏ nhất của a và b
    abs(a) // trả về giá trị tuyệt đối của a(thư viện cmath)
    swap(a,b) // hoán đổi giá trị của a và b
    pow(a,b) // trả về giá trị a^b(thư viện cmath)
    sqrt(a) // trả về căn bậc 2 của a(thư viện cmath)
    ceil(a) // làm tròn lên giá trị của a(thư viện cmath)
    //vd: ceil(3.14) = 4
    floor(a) // làm tròn xuống giá trị của a(thư viện cmath)
    // vd floor(3.94) = 3
    round(a) // làm tròn giá trị của a(thư viện cmath)
    // vd round(3.14) = 3, round(3.94) = 4
    __gcd(a,b) // trả về ước chung lớn nhất của a và b(thư viện algorithm)
    
    tolower(a) // chuyển kí tự a thành kí tự thường
    toupper(a) // chuyển kí tự a thành kí tự hoa
    isdigit(a) // kiểm tra xem a có phải là số không
    isalpha(a) // kiểm tra xem a có phải là chữ cái không
    isalnum(a) // kiểm tra xem a có phải là chữ cái hoặc số không
    islower(a) // kiểm tra xem a có phải là chữ cái thường không
    isupper(a) // kiểm tra xem a có phải là chữ cái hoa không

    getline(cin,s) // đọc một dòng từ bàn phím và lưu vào chuỗi s(string)
    cin.getline(s,50) // đọc một dòng từ bàn phím và lưu vào chuỗi s(char[])
                        với độ dài 50 kí tự

                        
    cout << fixed << setprecision(2) << 3.14159; // in ra số pi với 2 chữ số sau dấu phẩy
                                                // (thư viện iomanip)

    
    

                        // Một số hàm
//Kiểm tra số chẵn
#include<iostream>
using namespace std;
bool isEven(int n)
{
    return n%2 == 0;
}

// Kiểm tra số lẻ
#include<iostream>
using namespace std;
bool isOdd(int n)
{
    return n%2 != 0;
}

// Hàm kiểm tra sô nguyên tố
#include<iostream>
using namespace std;
bool isPrime(int n)
{
    if(n <= 1) return false;
    if(n <= 3) return true;
    for(int i=2 ; i*i <=n ; i++)
    {
        if(n%i == 0) return false;
    }
    return true;
}

//Hàm phân tích thừa số nguyên tố
#include<iostream>
using namespace std;
void PhanTich(int num)
{
    for(int i=2 ;i*i <=num ; i++)
    {
        while (num%i == 0)
        {
            cout << i << " ";
            num /= i;
        }
    }
    if(num !=1) cout << num;
}

//Hàm tìm chữ số đầu tiên của n
int ChuSoDau(int n)
{
    if(n<0) n*= -1;
    while(n>=10) n/=10;
    return n;
}

// Hàm tìm chữ số cuối cùng của n
int ChuSoCuoi(int n)
{
    if(n<0) n*= -1;
    return n%10;
}

// Hàm kiểm tra số chính phương
#include<iostream>
#include<cmath>
using namespace std;
bool isSquareNumber(int n)
{
    if(n < 0) return false;
    int x = sqrt(n);
    return x*x == n;
}

// Hàm kiểm tra số hoàn hảo
#include<iostream>
using namespace std;

bool isPerfectNumber(int n)
{
    if(n <= 1) return false;
    int sum = 1;
    for(int i=2 ; i*i <= n ; i++)
    {
        if(n%i == 0)
        {
            sum += i;
            if(i != n/i) sum += n/i;
        }
    }
    return sum == n;
}

//Hàm tìm UCLN
#include<iostream>
using namespace std;
int UCLN(int a, int b)
{
    if(!b) return a;
    else return UCLN(b, a%b);
}

//Hàm tìm BCNN
#include<iostream>
using namespace std;

long long BCNN(int a, int b)
{
    return 1LL*a/UCLN(a,b)*b;
}


//Hàm tính giai thừa
#include<iostream>
using namespace std;
long long factorial(int n)
{
    if(n == 0) return 1;
    return n*factorial(n-1);
}


//Hàm KIỂM TRA đối xứng
#include<iostream>
using namespace std;

bool isPalinDrome(int num) // với số
{
    int n = num;
    int rev = 0;
    while(n > 0)
    {
        rev = rev*10 + n%10;
        n /= 10;
    }
    return rev == num;
}

bool isPalinDrome(string s) // với chuỗi
{
    int n = s.length();
    for(int i=0 ; i<n/2 ; i++)
    {
        if(s[i] != s[n-i-1]) return false;
    }
    return true;
}

bool isPalinDrome(int a[1000],int n) // với mảng
{
    for(int i=0 ; i<n/2 ; i++)
    {
        if(a[i] != a[n-i-1]) return false;
    }
    return true;
}


// Hàm tìm số đối xứng
#include<iostream>
using namespace std;

int SoDoiXung(int num)
{
    if(num <10) return num;
    int rev = 0;
    while(num > 0)
    {
        rev = rev*10 + num%10;
        num /= 10;
    }
    return rev;
}


//Hàm đảo ngược mảng
#include<iostream>
using namespace std;

void Reverse(int a[1000],int n)
{
    for(int i=0 ; i<n/2 ; i++)
    {
        swap(a[i],a[n-i-1]);
    }
}


// Hàm tình tổng các chữ số
#include<iostream>
using namespace std;

int Sum(int n)
{
    int sum = 0;
    while(n > 0)
    {
        sum += n%10;
        n /= 10;
    }
    return sum;
}
// Hàm tính số FIBONACCY
#include<iostream>
using namespace std;

long long int Fibo(int n) // LƯU Ý : n<=40;
{
    if(n<=1) return n;
    else return Fibo(n-1) + Fibo(n-2);
}

//Hàm sắp xếp mảng
#include<iostream>
using namespace std;

void Sort(int a[1000],int n) // tăng dần
{
    for(int i=0 ; i<n-1 ; i++)
    {
        for(int j=i+1 ; j<n ; j++)
        {
            if(a[i] > a[j]) swap(a[i],a[j]);
        }
    }
}

void Sort(int a[1000],int n) // giảm dần
{
    for(int i=0 ; i<n-1 ; i++)
    {
        for(int j=i+1 ; j<n ; j++)
        {
            if(a[i] < a[j]) swap(a[i],a[j]);
        }
    }
}

//Hàm tìm giá trị lớn nhất trong mảng
#include<iostream>
using namespace std;

int Max(int a[1000],int n)
{
    int res = a[0];
    for(int i=1 ; i<n ; i++)
    {
        res = max(res,a[i]);
    }
    return res;
}

//Hàm tìm giá trị bé nhất trong mảng
#include<iostream>
using namespace std;
int Min(int a[1000],int n)
{
    int res = a[0];
    for(int i=1 ; i<n ; i++)
    {
        res = min(res,a[i]);
    }
    return res;
}

//Hàm tìm giá trị lớn THỨ HAI trong mảng
#include<iostream>
#include<climits>
using namespace std;
int SecMax(int a[1000],int n)
{
    int secMax = INT_MIN;
    int Max = INT_MIN;
    for(int i=0 ; i<n ; i++)
    {
        Max = max(Max,a[i]);
    }

    for(int i=0 ; i<n ; i++)
    {
        if(a[i] == Max) continue;
        secMax = max(secMax,a[i]);
    }
    return secMax;
}



// Hàm tính tổng các số có trong chuỗi(string)
#include<iostream>
#include<string>
using namespace std;

int Sum(string s)
{
    int tong = 0;
    int tam = 0;
    for(char c : s)
    {
        if(isdigit(c))
            tam = tam*10 + c - '0';
        else
        {
            tong += tam;
            tam = 0;
        }
        tong += tam;
    }
    return tong;
}


                // Một số chương trình cơ bản

// Mảng độc nhất (là xóa các phần tử trùng nhau)
#include<iostream>
#include<map>
using namespace std;

int main()
{
    int a[1000],n;
    cin >> n;
    map<int,int> mp;

    for(int i=0 ; i<n ; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }

    for(auto pair : mp)
    {
        cout << pair.first << " ";
    }
}

// Giá trị xuất hiện nhiều nhất trong mảng
#include<iostream>
#include<map>
using namespace std;

int MostFrequent(int a[1000],int n)
{
    map<int,int> mp;
    int res = 0;
    int Max = 0;

    for(int i=0 ; i<n ; i++)
    {
        mp[a[i]]++;
        if(mp[a[i]] > Max)
        {
            Max = mp[a[i]];
            res = a[i];
        }
        else if(mp[a[i]] == Max)
        {
            res = max(res,a[i]);
        }
    }

    return res;
}

//Học đếm trong mảng
// Đếm xem có bao nhiêu số X trong mảng a có n phần tử
#include<iostream>
using namespace std;
int main()
{
    int n,X;
    cin >> n >> X;
    int a,dem = 0;
    while (n--)
    {
        cin >> a;
        if(a == X) dem++;
    }
    cout << dem;
}

//Chương trình kiểm tra X có trong mảng a không
#include<iostream>
using namespace std;

int main()
{
    int n,x; // n là kích thước mảng, x là giá trị cần kiểm tra
    cin >> n >> x;
    bool found = false;
    int a[1000];
    for(int i=0; i<n;i++)
    {
        cin >> a[i];
        if(a[i] == x) found = true;
    }
    
    if(found) cout << "YES";
    else cout << "NO";

    return 0;
}

// Chương trình kiếm tra 3 số a,b,c có tạo thành tam giác không

#include <iostream>
using namespace std;

int main(){
    long long a,b,c;
    cin >> a >> b >>c;
    if(a+b>c && b+c>a && a+c>b) cout << "YES";
    else cout << "NO";

    return 0;
}

