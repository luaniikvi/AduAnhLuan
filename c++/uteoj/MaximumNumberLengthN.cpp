#include<iostream>
using namespace std;
int main()
{
    long long int len;cin >> len;
    long long int total;cin >> total;

    if((total) > len*9) 
    {
        cout << -1;
        return 0;
    }
    if(total == 0)
    {
        cout << 0;
        return 0;
    }

    while (len--)
    {
        cout << min(9ll,total);
        total-=9;
        if(total < 0) total = 0; 
    }
    

    return 0;
}