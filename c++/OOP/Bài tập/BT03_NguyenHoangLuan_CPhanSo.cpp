// Code by Nguyễn Hoàng Luân - 24162069
#include <iostream>
using namespace std;

// Nguyễn Hoàng Luân
int _gcd(int a, int b) { return (!b ? a : _gcd(b,a%b)); }
int _abs(int num) { return (num > 0 ? num : -num); }

class CPhanSo
{
private:
    int tu;
    int mau;
public:
    // Contructor
    CPhanSo();
    CPhanSo(const int& num);
    CPhanSo(const int& tu,const int& mau);
    CPhanSo(const CPhanSo& other);

    // Method
    void ChuanHoa();
    CPhanSo reverse() const;

    // Operator
        // Arithmetic
    CPhanSo operator+(const CPhanSo& other) const;
    CPhanSo operator+() const;
    CPhanSo operator-(const CPhanSo& other) const;
    CPhanSo operator-() const;
    CPhanSo operator*(const CPhanSo& other) const;
    CPhanSo operator/(const CPhanSo& other) const;

    CPhanSo operator++(int);
    CPhanSo operator++();
    CPhanSo operator--(int);
    CPhanSo operator--();

        // Comparison
    bool operator>(const CPhanSo& other) const;
    bool operator<(const CPhanSo& other) const;
    bool operator>=(const CPhanSo& other) const;
    bool operator<=(const CPhanSo& other) const;
    bool operator==(const CPhanSo& other) const;

        // Assignment
    void operator=(const CPhanSo& other);
    void operator+=(const CPhanSo& other);
    void operator-=(const CPhanSo& other);
    void operator*=(const CPhanSo& other);
    void operator/=(const CPhanSo& other);


    // in-out stream
    friend istream& operator>>(istream& is, CPhanSo& ps);
    friend ostream& operator<<(ostream& os, const CPhanSo& ps);


    // Get tử & mẫu
    
    //int* operator.*() const; --theo đề bài
    // .* không thể nạp chồng được

    // Thay thế = cách cast CPhanSo về int* cho giống với yêu cầu
    operator int*() const;


    // Destructor
    ~CPhanSo() = default; // Để compiler tự thêm phương thức hủy mặc định
};


// ==================Constructor====================
// Nguyễn Hoàng Luân
CPhanSo::CPhanSo(): tu(0) , mau(1){}
// Nguyễn Hoàng Luân
CPhanSo::CPhanSo(const int& num) : tu(num), mau(1){}
// Nguyễn Hoàng Luân
CPhanSo::CPhanSo(const int& tu,const int& mau): tu(tu), mau(mau) {
    if(!mau) this->mau = 1;
    this->ChuanHoa();
}
// Nguyễn Hoàng Luân
CPhanSo::CPhanSo(const CPhanSo& other){
    this->tu = other.tu;
    this->mau = other.mau;
}


// Nguyễn Hoàng Luân
// ======================Method=======================
void CPhanSo::ChuanHoa(){
    int ucln = _gcd(_abs(this->tu), _abs(this->mau));
    this->tu /= ucln;
    this->mau /= ucln;
    if(mau < 0){
        this->tu *= -1;
        this->mau *= -1;
    }
}
// Nguyễn Hoàng Luân
CPhanSo CPhanSo::reverse() const{
    return CPhanSo(this->mau,this->tu);
}



// Nguyễn Hoàng Luân
//=====================Operator===================
    // Arithmetic
CPhanSo CPhanSo::operator+(const CPhanSo& other) const{
    return CPhanSo(this->tu*other.mau + other.tu*this->mau, 
                  this->mau * other.mau);
}
// Nguyễn Hoàng Luân
CPhanSo CPhanSo::operator+() const{
    return *this;
}
// Nguyễn Hoàng Luân
CPhanSo CPhanSo::operator-(const CPhanSo& other) const{
    return CPhanSo(this->tu*other.mau - other.tu*this->mau, 
                  this->mau * other.mau);
}
// Nguyễn Hoàng Luân
CPhanSo CPhanSo::operator-() const{
    return CPhanSo(-this->tu,this->mau);
}
// Nguyễn Hoàng Luân
CPhanSo CPhanSo::operator*(const CPhanSo& other) const{
    return CPhanSo(this->tu*other.tu, this->mau*other.mau);
}
// Nguyễn Hoàng Luân
CPhanSo CPhanSo::operator/(const CPhanSo& other) const{
    return (*this) * other.reverse();
}



// Nguyễn Hoàng Luân
CPhanSo CPhanSo::operator++(int){
    CPhanSo temp(*this);
    this->tu += this->mau;
    return temp;
}
// Nguyễn Hoàng Luân
CPhanSo CPhanSo::operator++(){
    this->tu += this->mau;
    return *this;
}
// Nguyễn Hoàng Luân
CPhanSo CPhanSo::operator--(int){
    CPhanSo temp(*this);
    this->tu -= this->mau;
    return temp;
}
// Nguyễn Hoàng Luân
CPhanSo CPhanSo::operator--(){
    this->tu -= this->mau;
    return *this;
}



// Nguyễn Hoàng Luân
    //  Comparison
bool CPhanSo::operator>(const CPhanSo& other) const{
    return this->tu*other.mau > this->mau*other.tu;
}
// Nguyễn Hoàng Luân
bool CPhanSo::operator<(const CPhanSo& other) const{
    return other > *this;
}
// Nguyễn Hoàng Luân
bool CPhanSo::operator>=(const CPhanSo& other) const{
    return *this > other || *this == other;
}
// Nguyễn Hoàng Luân
bool CPhanSo::operator<=(const CPhanSo& other) const{
    return other <= *this;
}
// Nguyễn Hoàng Luân
bool CPhanSo::operator==(const CPhanSo& other) const{
    return this->tu == other.tu && this->mau == other.mau;
}



// Nguyễn Hoàng Luân
        // Assignment
void CPhanSo::operator=(const CPhanSo& other){
    this->tu = other.tu;
    this->mau = other.mau;
}
// Nguyễn Hoàng Luân
void CPhanSo::operator+=(const CPhanSo& other){
    *this = *this + other;
}
// Nguyễn Hoàng Luân
void CPhanSo::operator-=(const CPhanSo& other){
    *this = *this - other;
}
// Nguyễn Hoàng Luân
void CPhanSo::operator*=(const CPhanSo& other){
    *this = *this * other;
}
// Nguyễn Hoàng Luân
void CPhanSo::operator/=(const CPhanSo& other){
    *this = *this / other;
}



// Nguyễn Hoàng Luân
// =============in-out stream================
istream& operator>>(istream& is, CPhanSo& ps){
    is >> ps.tu >> ps.mau;
    if(ps.mau == 0) ps.mau = 1;
    ps.ChuanHoa();
    return is;
}
// Nguyễn Hoàng Luân
ostream& operator<<(ostream& os, const CPhanSo& ps){
    os << ps.tu << '/' << ps.mau;
    return os;
}


// Nguyễn Hoàng Luân
// =============Get tử & mẫu===============
CPhanSo::operator int*() const{ // cast về int*
    int* ps = new int[2];
    ps[0] = this->tu;
    ps[1] = this->mau;
    return ps;
}

int main(){
    CPhanSo a(1,2);
    // a /= CPhanSo(2,3);
    a *= CPhanSo(2,3);
    // cout << (a == CPhanSo(1,2));
    cout << a << endl;

    int* ps = a; // Lấy tử & mẫu từ phân số a
    cout << ps[0] << '/' << ps[1] << endl;

    CPhanSo b = 99;
    b += a;
    cout << b << endl;

    CPhanSo c = 1000;
    cout << c++ << endl;
    cout << ++c << endl;
}