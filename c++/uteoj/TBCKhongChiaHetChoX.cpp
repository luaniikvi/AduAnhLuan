#include<iostream>
#include<cmath>
using namespace std;


int main()
{
    int n,x;
    cin >> n >> x;
    int temp;
    int total = 0,size = 0;

    for(int i=0 ; i<n ; i++)
    {
        cin >> temp;
        if (x % temp != 0)
        {
            total += temp;
            size++;
        }
    }   
    //cout << total << endl;
    cout << round((double)total/size);
}