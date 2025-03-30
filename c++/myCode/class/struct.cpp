#include<iostream>
using namespace std;

struct Point
{
    int x;
    int y;

    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    Point operator+(Point p)
    {
        return Point(x + p.x, y + p.y);
    }

    Point operator-(Point p)
    {
        return Point(x-p.x,y-p.y);
    }

    auto operator*(Point p)
    {
        return x*p.x + y*p.y;
    }


    friend ostream& operator<<(ostream& os, Point p)
    {
        os << '{' << p.x << ',' << p.y << '}';
        return os;
    }
};

int main()
{
    Point p(1,2);
    cout << p << endl;
}