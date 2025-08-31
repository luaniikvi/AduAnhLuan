//Code by hluan-24162069 (luaniikvi)

#include <iostream>
#include <cmath>
using namespace std;

struct Point{
private:
    int x;
    int y;
public:
    // structure
    Point(): x(0),y(0){};
    Point(int x, int y): x(x), y(y){};

    // Tính khoảng cách đến 1 điểm bất kì
    double To(Point p) const  {
        return sqrt(pow(this->x - p.x,2) + pow(this->y - p.y, 2));
    }
    //
    Point Symmetry()       const {
        return Point(-x,-y);
    };
    Point AxisymmetricOx() const {
        return Point(x,-y);
    };
    Point AxisymmetricOy() const {
        return Point(-x,y);
    };


    friend istream& operator>> (istream &is, Point &p){
        is >> p.x >> p.y;
        return is;
    }
    friend ostream& operator<< (ostream &os,const Point p){
        os << '(' << p.x << ',' << p.y << ')'; 
        return os;
    }

    ~Point(){};
};

int main(){
    Point a;
    cin >> a;
    cout << a;
}