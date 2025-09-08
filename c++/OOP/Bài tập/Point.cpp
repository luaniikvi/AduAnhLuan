//Code by hluan-24162069 (luaniikvi)

#include <iostream>
#include <cmath>
using namespace std;

struct Point{
private:
    double x;
    double y;
public:
    // structure
    Point(): x(0),y(0){};
    Point(double x, double y): x(x), y(y){};

    // Lấy giá trị
    double getX(){return this->x;}
    double getY(){return this->y;}

    //Tính khoảng cách đến 1 điểm bất kì
    double To(Point p) const  {
        return sqrt(pow(this->x - p.x,2) + pow(this->y - p.y, 2));
    }
    //đối xứng qua tâm (0,0)
    Point Symmetry()       const {return Point(-x,-y);};
    // đối xứng qua trục Ox
    Point AxisymmetricOx() const {return Point(x,-y);};
    // đối xứng qua trục Oy
    Point AxisymmetricOy() const {return Point(-x,y);};


    // in-stream -- nhập
    friend istream& operator>> (istream &is, Point &p){
        is >> p.x >> p.y;
        return is;
    }
    // out-stream -- xuất
    friend ostream& operator<< (ostream &os,const Point p){
        os << '(' << p.x << ',' << p.y << ')'; 
        return os;
    }

    ~Point(){}; // destructure
};

int main(){
    Point a;
    cin >> a;
    cout << a;
}