#include<iostream>
using namespace std;

int main()
{
    int x,y;
    cin >> x >> y;

    int stt;

    if(x==0 || y ==0)
    {
        if(x == y)
        {
            stt = 0;
        }
        else if( y == 0){
            stt = 5;
        }
        else stt = 6;
    }
    else
    {
        if(x > 0 && y > 0)
        {
            stt = 1;
        }
        else if(x < 0 && y > 0)
        {
            stt = 2;
        }
        else if(x < 0 && y <0)
        {
            stt = 3;
        }
        else
        {
            stt = 4;
        }
    }

    cout << stt;

    return 0;
}