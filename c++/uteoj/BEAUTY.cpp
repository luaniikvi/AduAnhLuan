#include<iostream>
#include<cmath>
using namespace std;
bool laSoDep(int num);

int main()
{
    int l,r;
    cin >> l >> r;

    int count = 0;
    for(int i = l ; i<r+1 ; i++)
    {
        if(laSoDep(i)) count++;
    }


    cout << count;

    return 0;
}


bool laSoDep(int num)
{
    int count =0;
    for(int i=1; i<num; i++)
    {
        if(num%i == 0) count ++;
    }

    return (count == 2);
}