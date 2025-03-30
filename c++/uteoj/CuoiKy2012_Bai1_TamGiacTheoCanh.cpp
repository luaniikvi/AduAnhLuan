#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isnt(int num);
bool isnt2(int num)
{
    if(num <=1) return false;
    if(num <= 3) return true;
    if(num % 2 == 0 || num % 3 == 0) return false;
    for(int i=5 ; i*i <= num ; i+= 6)
    {
        if(num %i ==0 || num %(i+2) == 0) return false;
    }

    return true;
}

int main()
{
    cout << isnt(4) << endl;
    cout << isnt2(4);

    return 0;
}

bool isnt(int num)
{
    if(num <=1) return false;
    if(num <= 3) return true;
    if(num % 2 == 0 || num % 3 == 0) return false;
    for(int i=5 ; i*i <= num ; i+= 6)
    {
        if(num %i ==0 || num %(i+2) == 0) return false;
    }

    return true;
}