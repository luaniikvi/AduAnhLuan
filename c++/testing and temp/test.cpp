#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    string str = "ABCD";
    str.erase(2,1);
    cout << str;
}