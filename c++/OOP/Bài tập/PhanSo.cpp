//Code by hluan-24162069 (luaniikvi)

#include <iostream>
#include <algorithm>
#define MAX_SIZE 1000

using namespace std;

struct PhanSo
{
private:
    int tu;
    int mau;
public:
    
    // structure
    PhanSo(): tu(0),mau(1){};
    PhanSo(int number) : tu(number), mau(1){}; 
    PhanSo(int tu, int mau): tu(tu), mau(mau){this->normalize();}
    PhanSo(int arr[2]): tu(arr[0]), mau(arr[1]){this->normalize();}
    
    //function
    void normalize(){
        if(this->mau == 0) return;
        int gcd = __gcd(abs(this->tu),abs(this->mau));
        this->tu  /= gcd;
        this->mau /= gcd;
        if(this->mau < 0) *this = PhanSo(-tu,-mau);
    }
    bool isInf(){return this->mau == 0;}
    PhanSo reverse(){return PhanSo(this->mau,this->tu);}
    double trueValue()  {
        return (double)tu/mau;
    }
    string getSign(){
        if(this->isInf()) return "inf";
        if(this->tu == 0) return "0";
        if(this->tu > 0)  return "+";
        return "-";
    }
    
    //operator
    PhanSo operator+(PhanSo ps);
    void operator+= (PhanSo ps){*this = *this + ps;}

    PhanSo operator-(PhanSo ps);
    void operator-=(PhanSo ps){*this = *this - ps;}

    PhanSo operator*(PhanSo ps);
    void operator*= (PhanSo ps){*this = (*this) * ps;}
    PhanSo operator/(PhanSo ps);
    void operator/=(PhanSo ps){*this = *this/ps;}

    void operator=(PhanSo ps);
    void operator=(int ps[2]);
    void operator=(int number);

    bool operator==(PhanSo ps);
    bool operator>(PhanSo ps);
    bool operator>=(PhanSo ps);
    bool operator<(PhanSo ps);
    bool operator<=(PhanSo ps);


    //in-stream
    friend istream& operator>>(istream& is, PhanSo& ps){
        is >> ps.tu >> ps.mau;
        ps.normalize();
        return is;
    }

    // out-stream
    friend ostream& operator<< (ostream &os, PhanSo ps){
        if(ps.isInf()) os << "Inf";
        else if (ps.mau == 1) os << ps.tu;
        else os << ps.tu << "/" << ps.mau;
        return os;
    }

    //destructure
    ~PhanSo(){}
};

PhanSo PhanSo::operator+(PhanSo ps){
    this->tu = this->tu*ps.mau + this->mau*ps.tu;
    this->mau *= ps.mau;
    this->normalize();
    return *this;
}
PhanSo PhanSo::operator-(PhanSo ps){
    this->tu = this->tu*ps.mau - this->mau*ps.tu;
    this->mau *= ps.mau;
    this->normalize();
    return *this;
}
PhanSo PhanSo::operator*(PhanSo ps){
        this->tu  *= ps.tu;
        this->mau *= ps.mau;
        this->normalize();
        return *this;
}
PhanSo PhanSo::operator/(PhanSo ps){
    ps = ps.reverse();
    *this *= ps;
    return *this;
}
void PhanSo::operator=(PhanSo ps){
    this->tu  = ps.tu;
    this->mau = ps.mau;
}
void PhanSo::operator=(int ps[2]){
    this->tu  = ps[0];
    this->mau = ps[1];
}
void PhanSo::operator=(int number){
    *this = PhanSo(number);
}
bool PhanSo::operator==(PhanSo ps){
    return this->tu == ps.tu && this->mau==ps.mau;
}
bool PhanSo::operator>(PhanSo ps) {
    return this->trueValue() > ps.trueValue();
}
bool PhanSo::operator>=(PhanSo ps){
    return *this>ps || *this == ps;
}
bool PhanSo::operator<(PhanSo ps){
    return ps>*this;
}
bool PhanSo::operator<=(PhanSo ps){
    return ps>*this || ps == *this;
}
// Tìm max giữa 2 phân số
PhanSo max(PhanSo a, PhanSo b){
    return (a > b ? a : b);
}
// In mảng phân số
void Print(PhanSo arr[], int size){
    for(int i=0 ; i<size ; i++)
        cout << arr[i] << " ";
}
// In số âm trong mảng
void PrintNegative(PhanSo arr[], int size){
    for(int i=0 ; i<size ; i++)
        if(arr[i].getSign() == "-")
            cout << arr[i] << " ";
}
// Tổng các số trong mảng
PhanSo Sum( PhanSo arr[], int size){
    PhanSo ans(0);
    for(int i=0 ; i<size ; i++)
        ans += arr[i];
    return ans;
}
// Đếm các phân số âm
int CountNegative(PhanSo arr[], int size) {
    int cnt = 0;
    for(int i=0 ; i<size ; i++)
        if(arr[i].getSign() == "-") cnt++;
    return cnt;
}
// Có số âm trong mảng
bool HasAnyNegative(PhanSo arr[], int size){
    for(int i=0 ; i<size ; i++)
        if(arr[i].getSign() == "-") return true;
    return false;
}
// Tất cả đều là số âm
bool IsAllNegative(PhanSo arr[], int size){
    for(int i=0 ; i<size ; i++)
        if(arr[i].getSign() != "-") return false;
    return true;
}
// Phân số lớn nhất trong mảng
PhanSo Max( PhanSo arr[], int size){
    PhanSo ans(0);
    for(int i=0 ; i<size ; i++)
        ans = max(ans,arr[i]);
    return ans;
}

main(){
    PhanSo a[MAX_SIZE], Max(0);
    int n;
    cout << "Nhập số lượng phân số: "; cin >> n;
    for(int i=0 ; i<n ; i++){
        cout << i+1 << ". ";
        cin >> a[i];
    }
    cout << CountNegative(a,n);
}