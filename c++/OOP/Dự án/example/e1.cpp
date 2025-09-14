#include <iostream>
using namespace std;

class A{
public:
    int a;
    virtual void input(){
        cin >> this->a;
    }
};

class B :public A{
public:
    int b;
    void input(){
        cin >> this->a;
        cin >> this->b;
    }
};

int main(){}