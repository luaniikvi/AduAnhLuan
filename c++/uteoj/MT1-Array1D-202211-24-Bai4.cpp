#include<iostream>
using namespace std;
int main()
{
    int input,size,dem2=0,dem5=0;
    cin >> size;
    for(int i=0 ; i<size ; i++)
    {
        cin >> input;
        if(input == 0) continue;
        while (input %2 ==0)        
        {
            input/=2;
            dem2++;
        }
        while (input %5 ==0)        
        {
            input/=5;
            dem5++;
        }
    }

    cout << min(dem2,dem5);
    return 0;
}