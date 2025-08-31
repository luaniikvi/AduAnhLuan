//Code by hluan-24162069 (luaniikvi)

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
// Point struct
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

struct TamGiac
{
private:
    Point point[3]; // 3 points
    double dis[3]; // 3 distances
public:
    //structure
    TamGiac(){};

    // bất đẳng thức tam giác
    bool isTriagle(double dis[3]);
    // phân loại tam giác
    string PhanLoai();
    // Tìm trọng tâm tam giác
    Point Centroid(){
        if(!isTriagle(dis))
            cout << "Đây kh phải tam giác nên kh có trọng tâm.";
        else{
            double xG =(point[0].getX() + point[1].getX() + point[2].getX())/3; 
            double yG =(point[0].getY() + point[1].getY() + point[2].getY())/3;
            return Point(xG,yG); 
        }
        return Point();
    } 

    // in-stream -- nhập
    friend istream& operator>>(istream& is, TamGiac &tamgiac){
        // nhập 3 đỉnh
        for(int i=0 ; i<3 ; i++)
            is >> tamgiac.point[i];
        // tính 3 khoảng cách
        for(int i=0 ; i<3 ; i++)
        {
            tamgiac.dis[i] = tamgiac.point[i].To(tamgiac.point[(i+1)%3]);
            //cout << tamgiac.dis[i] << " ";
        }
        sort(tamgiac.dis,tamgiac.dis+3);
        return is;
    }
    // out-stream -- in
    friend ostream& operator<<(ostream& os, TamGiac tamgiac){
        for(int i=0 ; i<3 ; i++)
            os << tamgiac.point[i] << " ";
        return os;
    }

    ~TamGiac(){};// destructure
};

bool TamGiac::isTriagle(double dis[3]){
    return dis[0] < dis[1]+dis[2]
    && dis[1] < dis[0]+dis[2]
    && dis[3] < dis[1] + dis[0];
}
string TamGiac::PhanLoai(){
    sort(begin(dis),end(dis));
    double a,b,c;
    a = dis[0]; b = dis[1]; c = dis[2];
    if(!isTriagle(dis)) return "Không phải tam giác";
    if(c*c < a*a + b*b) return "Tam giác nhọn";
    if(c*c == a*a + b*b) return "Tam giác vuông";
    return "Tam giác tù";
}

main(){}