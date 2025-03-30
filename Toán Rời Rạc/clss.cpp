#include<iostream>
using namespace std;

class Bool
{
    public:
    bool value = 0;
    //set value
    Bool(bool x)
    {
        this->value = x;
    }
    Bool(){}

    // or
    Bool operator|| (Bool b)
    {
        return (this->value || b.value);
    }

    // and
    Bool operator&&(Bool b)
    {
        return (this->value && b.value);
    }


    // hoac xor
    Bool operator^(Bool b)
    {
        return (this->value ^ b.value);
    }

    // keo theo -->
    Bool operator-(Bool b)
        {
            if(this->value == 1 && b.value == 0) return 0;
            return 1;
        }

    // not
    Bool operator!()
    {
        return !this->value;
    }

    // tuong duong <->
    Bool operator==(Bool b)
    {
        return (this->value == b.value);
    }

    // cout
    friend ostream& operator<<(ostream& os, Bool b)
    {
        os << b.value;
        return os;
    }

    // cin
    friend istream& operator>>(istream& is, Bool& b)
    {
        is >> b.value;
        return is;
    }

};

int main()
{
    bool list[]={1,0};
    Bool res1,res2,res3;
    // p -> q
    // !p || q
    for(Bool p : list)
        for(Bool q : list)
        {
            res1 = ((p-q) && q ) ;
            res2 = ((p-q) && q )- (p);
            cout << "p: "<< p << "    q: " << q;
            cout << "    res1: "  << res1;
            cout << "    res2: "  << res2;
            //cout << "    res3: "  << res3;

            cout << endl;
        }

    return 0;
}