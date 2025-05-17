#include<iostream>
#include<algorithm>
#include<sstream>
using namespace std;

int Count(long duration)
{
    int dem = 0;
    int hour = 12;
    int min = 00;

    while (duration--)
    {
        min++;
        if(min == 60)
        {
            min = 0;
            hour ++;
            if(hour == 13) hour = 1;
        }
        if(hour < 10)
        {
            if(min%10 - min/10 == min/10 - hour) dem ++;
        }
        else if(min%10 - min/10 == min/10 - hour%10 
        && min/10 - hour%10 == hour%10 - hour/10) dem++;
    }
    
    return dem;
}

int main()
{

    long D;cin >> D;
    if(D <=720 ) cout << Count(D);
    else cout << (D/720)*Count(720) + Count(D%720);
}