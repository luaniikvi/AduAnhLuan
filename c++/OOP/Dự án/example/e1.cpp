#include <iostream>
#include <conio.h>
using namespace std;

class A{
public:
    A(){ cout << "A()" << endl;}
    virtual ~A() {cout << "~A()" << endl;}
};
class B : virtual public A{
public:
    B(){ cout << "B()" << endl;}
    ~B() {cout << "~B()" << endl;}
};
class C :virtual public A{
public:
    C(){ cout << "C()" << endl;}
    ~C() {cout << "~C()" << endl;}
};
class D : public B,C{
public:
    D(){ cout << "D()" << endl;}
    ~D() {cout << "~D()" << endl;}
};

int main(){
    A* p = new D;
    delete p;
    cout << "Pause";
    getch();
    return 0;
}