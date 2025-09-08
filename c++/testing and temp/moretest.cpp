#include <iostream>
#include <algorithm>

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


void nhapPS(PhanSo* ps){ cin >> *ps; }
void xuatPS(PhanSo* ps){ cout << *ps; }

main(){


    PhanSo ps1,ps2;
    PhanSo total = ps1 + ps2;

}