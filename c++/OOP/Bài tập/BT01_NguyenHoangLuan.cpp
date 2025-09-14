// Code by Nguyễn Hoàng Luân - 24162069 
// 100% cam kết code bằng kinh nghiệm + thực lực, không chatGPT

#include <iostream>

using namespace std;

int abs(int num) { return (num > 0 ? num : -num);}
int _gcd(int a, int b) { return (!b ? a : _gcd(b, a%b));}

class PhanSo
{
private:
    int tu;
    int mau;
public:
    // Contructor
    PhanSo() : tu(0), mau(1) {};
    PhanSo(const int num): tu(num), mau(1){};
    PhanSo(int tu, int mau);

    // Method
    void RutGon();
    void ChuanHoa();
    
    // Phép toán
    PhanSo cong(PhanSo o) const;
    PhanSo nhan(PhanSo o) const;

    // phép so sánh
    bool soSanhBang(PhanSo o) const;
    bool soSanhBe(PhanSo o) const;

    // phép gắn
    PhanSo& gan(PhanSo o);
    PhanSo& gan(const int num);

    //in-out stream
    void Nhap();
    void Xuat(string end) const;

    // Destructor
    ~PhanSo() = default;
};
// Nguyễn Hoàng Luân
PhanSo::PhanSo(int tu, int mau){
    this->tu = tu;
    this->mau = (mau == 0 ? 1 : mau);
    this->ChuanHoa();
}
// Nguyễn Hoàng Luân
void PhanSo::Nhap(){
    cin >> this->tu;
    cin >> this->mau;
    // Nếu mẫu = 0 -> cho mẫu = 1
    this->mau = (this->mau == 0 ? 1 : this->mau);
    this->ChuanHoa();
};
// Nguyễn Hoàng Luân
void PhanSo::Xuat(string end = "\n") const{
    cout << this->tu << "/" << this->mau << end;
};
// Nguyễn Hoàng Luân
void PhanSo::RutGon(){
    int ucln = _gcd(abs(tu),abs(mau));
    this->tu /= ucln;
    this->mau /= ucln;
}
// Nguyễn Hoàng Luân
void PhanSo::ChuanHoa(){
    this->RutGon();
    if(this->mau < 0) *this = PhanSo(-tu,-mau);
};
// Nguyễn Hoàng Luân
PhanSo PhanSo::cong(const PhanSo o) const{
    int newTu = tu*o.mau + mau*o.tu;
    int newMau = mau*o.mau;
    return PhanSo(newTu,newMau);
};
// Nguyễn Hoàng Luân
PhanSo PhanSo::nhan(PhanSo o) const{
    return PhanSo(this->tu*o.tu, this->mau*o.mau);
};
// Nguyễn Hoàng Luân
bool PhanSo::soSanhBang(PhanSo o) const{
    return this->tu == o.tu && this->mau == o.mau;
}
// Nguyễn Hoàng Luân
bool PhanSo::soSanhBe(PhanSo o) const{
    return this->tu*o.mau < this->mau*o.tu;
}

// Nguyễn Hoàng Luân
PhanSo& PhanSo::gan(PhanSo o){
    *this = o;
    return *this;
}
// Nguyễn Hoàng Luân
PhanSo& PhanSo::gan(const int num){
    *this = PhanSo(num);
    return *this;
}

// Nguyễn Hoàng Luân
int main(){
    PhanSo a(1,2), b(1,2), c(1,9);
    a.gan(b.gan(c)).Xuat(""); a = b = c;
    cout << boolalpha << a.soSanhBang(b) << endl;
    cout << boolalpha << a.soSanhBe(c) << endl;
    PhanSo new1;
    new1.Nhap();
    new1.Xuat();
}

//luaniikvi