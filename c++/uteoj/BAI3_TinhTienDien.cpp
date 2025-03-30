#include<iostream>
using namespace std;
int main()
{   
    int x;
    cin >> x;
    long long money = 0;
    while (x > 0)
    {
        if(x >= 145) money += 1594;
        else if(x >= 145 - 48) money +=1214;
        else if(x >= 145 - 48*2) money += 1004;
        else money += 600;
        x--;
    }
    
    cout << money;
}