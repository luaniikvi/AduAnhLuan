#include<iostream>
#include<map>

using namespace std;
int main()
{
    int a[10];
    for( int &i : a)
    cout << &i << endl;
}