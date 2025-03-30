#include<iostream>
using namespace std;

struct Time{
    public:
    int h;
    int m;
    int s;
    void Nhap()
    {
        cin >> this->h >> this->m >> this->s;
    }

    friend istream& operator>>(istream& is, Time t)
    {
        is >> t.h >> t.m >> t.s;
        return is;
    }
};
int main()
{
    Time t;
    t.Nhap();
    
    cout << '1' << endl;
    cout << t.h << ' ' << t.m << ' ' << t.s << endl;

    cin >> t;
    cout << '2' << endl;
    cout << t.h << ' ' << t.m << ' ' << t.s << endl;
    return 0;
}