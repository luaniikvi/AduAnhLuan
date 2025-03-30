#include<iostream>
using namespace std;

bool isTrangle(int &a,int &b,int &c){
    return(a+b>c && a+c>b && c+b>a);
}

int main()
{
    int d[3];
    for(int i=0 ; i<3 ; i++)
    {
        cin >>d[i];
    }
    //cout << "arr: " << d[0]; 

    int *max = &d[0];
    for(int& num : d)
    {
        if(num > *max) max = &num;
    }
    cout << "max_ptr add: " << &max << endl;
    cout << "d[2] add: " << &d[2] << "  " << *max << endl;

    //int count =0;
    while(!isTrangle(d[0],d[1],d[2]))
    {
        *max -=1;
    }

    cout << d[0]  << " "<< d[1] << " "<< d[2] << endl;
    cout << "max_ptr add: " << &max << endl;
    cout << "d[2] add: " << &d[2] << endl;

    return 0;
}