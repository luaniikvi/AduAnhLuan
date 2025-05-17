#include<iostream>
using namespace std;


int direction = 1,pos = 0,control;
int main()
{
    int n;cin >> n;
    for(int i=0 ; i<n ; i++)
    {
        cin >> control;
        if(control == 1) pos += direction;
        else if(control == 2) pos -= direction;
        else direction *= -1;

        if(pos < 0) pos = 0;
    }
    cout << pos;
}