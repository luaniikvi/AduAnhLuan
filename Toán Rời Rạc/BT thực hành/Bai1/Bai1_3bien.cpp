#include<iostream>
using namespace std;

struct Bool{
    bool value = 0;
    //set value
    Bool(bool x): value(x){};
    Bool(){};
    // hay or
    Bool operator| (Bool b){
        return (this->value || b.value);
    }
    //  va and
    Bool operator&(Bool b){
        return (this->value && b.value);
    }
    // hoac xor
    Bool operator^(Bool b){
        return (this->value ^ b.value);
    }
    // keo theo -->
    Bool operator-(Bool b){
            if(this->value == 1 && b.value == 0) return 0;
            return 1;
    }
    // not
    Bool operator!(){
        return !this->value;
    }
    // tuong duong <->
    Bool operator==(Bool b){
        return (this->value == b.value);
    }
    // cout
    friend ostream& operator<<(ostream& os, Bool b){
        os << b.value;
        return os;
    }
    // cin
    friend istream& operator>>(istream& is, Bool& b){
        is >> b.value;
        return is;
    }
};

int main()
{
    freopen("task.out", "w", stdout);
    bool list[]={1,0};
    string debai = "(p->q)^r";
    cout << "p q r " << debai << endl;
    for(Bool p : list)
        for(Bool q : list)
            for(Bool r : list)
            {
                Bool res = (p-q)^r; //De bai
                cout << p << " " << q << " " << r << " " << res;
                cout << endl;
            }
}