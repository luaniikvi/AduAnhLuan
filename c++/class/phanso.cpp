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
    }

    friend ostream& operator<< (ostream& os , phanso a)
    {
        os << a.tu << '/' << a.mau;
        return os;
    }
};

int main()
{
    phanso list[100];
    int n;cin >> n;

    phanso sum(0);

    while (n--)
    {
        int tu,mau; cin >> tu >> mau;
        sum = sum+phanso(tu,mau);
    }
    
    cout << sum;
}
