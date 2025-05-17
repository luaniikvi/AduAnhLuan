#include<iostream>
using namespace std;

int PayMoney(int kwh);

int main()
{
    int dien;
    cin >> dien;

    cout << PayMoney(dien);

    return 0;
}

int PayMoney(int kwh)
{
    int money = 0;
    while(kwh > 0)
    {
        if(kwh > 144)
        {
            money += 1594;
        }
        else if(kwh > 96)
        {
            money += 1214;
        }
        else if(kwh > 48)
        {
            money += 1004;
        }
        else if(kwh > 0)
        {
            money += 600;
        }
        kwh --;
    }


    return money;
}