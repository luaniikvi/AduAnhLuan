#include <iostream>
#include <random>
#include <ctime>
using namespace std;

string key = "TYIFHKVMBAQ";

int main()
{
    srand(time(nullptr));
    int switch_amount = 11;
    while(switch_amount--)
    {
        int ran = rand() % key.length();
        cout << key[ran] << " ";
        key.erase(ran,1);
        ran = rand() % 2;
        if(ran) cout << "tsun\n";
        else cout << "xin\n";
    }
}