#include<iostream>
#include<bits/stdc++.h>
#include"BigNum.hpp"
using namespace std;

int f(char *s)
{
    static int c = 0 ;
    if(*s == NULL) return c;
    else
    {
        c++;return f(s+1);
    }
}
int main()
{
    char *s = "abc";
    if(s+3 == NULL) cout << "eys";
    cout << f(s);

}