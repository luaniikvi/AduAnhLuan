#include <iostream>

using namespace std;

class Person{
public:
    string name = "tunr";
};

class A:virtual public Person{
    public:
        string ID;
};
class B:virtual public Person{
    public :
        int age;
};

class C: public A,B{
    void Input(){
        cin >> this->name;
        cin >> this->ID;
        cin >> this->age;
    }
    string getName(){
        return this->name;
    }
};