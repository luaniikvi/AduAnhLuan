#include<iostream>
#include<algorithm>
using namespace std;
struct phanso
{
public:
    int tu = 0;
    int mau = 1;
    phanso(){}
    phanso(int a){
        this->tu = a;
    }
    phanso(int a,int b){
        this->tu = a;
        this->mau = b;
    }

    phanso& operator+(phanso other)
    {
        this->tu = this->tu*other.mau + this->mau*other.tu;
        this->mau *= other.mau;
        int ucln = __gcd(this->tu,this->mau);
        this->tu /=ucln;
        this->mau /=ucln;
        return *this;
    }

    friend ostream& operator<< (ostream& os , phanso a)
    {
        if(a.mau == 1){
            os << a.tu;
            return os;
        }
        os << a.tu << '/' << a.mau;
        return os;
    }
    friend istream& operator>> (istream& is, phanso& a)
    {
        cin >> a.tu >> a.mau;
        return is;
    }
};

int main()
{
    //phanso list[100];
    cout << "Nhap so luong phan so muon cong: ";
    int n;cin >> n;

    phanso sum(0);

    while (n--)
    {
        phanso ps;
        cin >> ps;
        sum = sum+ps;
    }
    
    cout << sum;
}
