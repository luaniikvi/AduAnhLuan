#include<iostream>
#include<cmath>
#include<vector>
#include<climits>
using namespace std;

class dir{
public:
    int x;
    int y;
    dir()
    {
        x = 0;
        y = 0;
    }
    dir(int a,int b)
    {
        x = a;
        y = b;
    }
    
    double length()
    {
        return sqrt(x*x + y*y);
    }
};

int _max(int a,int b)
{
    return (a>b?a:b);
}
int _min(int a,int b)
{
    return (a<b?a:b);
}
bool checkIn(int x0,int y0, vector<vector<int>> list);
int main()
{
    int size = 2;
    //cin >> size;    
    int x_min = INT_MAX;
    int x_max = INT_MIN;
    int y_min = INT_MAX;
    int y_max = INT_MIN;

    vector<vector<int>> list(size,vector<int>(4)); // x1 y1 x2 y2
    // list[0][0] = 1;list[0][1] = 1;
    // list[0][2] = 2;list[0][3] = 2;
    // list[1][0] = 1;list[1][1] = 1;
    // list[1][2] = 3;list[1][3] = 3;

    for(int i=0 ; i<size ; i++)
    {
        for(int j=0 ; j< 4 ; j++)
        {
            cin >> list[i][j];
            x_min = _min(x_min,list[i][0]);
            x_max = _max(x_max,list[i][2]);
            y_min = _min(y_min,list[i][1]);
            y_max = _max(y_max,list[i][3]);
        }
    }

    int count=0;
    for(int x0 = x_min ; x0<= x_max ; x0++)
    {
        for(int y0 = y_min ; y0<= y_max ; y0++)
        {
            if(checkIn(x0,y0,list)){
                count++;
            }
        }
    }
    cout << count;

    return 0;
}

bool checkInArea(dir point , int x1, int y1,int x2,int y2)
{
    int x = point.x; 
    int y = point.y;
    return (x>=x1 && x<=x2 && y>=y1 && y<=y2);
}

bool checkIn(int x0,int y0, vector<vector<int>> list)
{
    for(vector<int> &pair : list)
    {
        dir point(x0,y0);
        if(checkInArea(point,pair[0],pair[1],pair[2],pair[3]))
        {
            return true;
        }
    }
    return false;
}