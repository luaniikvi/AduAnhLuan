#include<iostream>
using namespace std;
int  main()
{   
    int n;
    cin >> n;
    int a[1000];
    int b[1000];
    int b_size = 0;

    bool check;

    for(int i=0 ;i < n ; i++)
    {
        cin >> a[i];
        if(i == 0) check == false;
        else 
        {
            for(int j=0 ; j<b_size; j++)
            {
                if(a[i] == b[j])
                {
                    check = true;
                    break;
                }
                check = false;
            }
        }
        if(!check)
        {
            b[b_size] = a[i];
            b_size++;
        }
    }

    for(int i= 0 ; i<b_size ; i++)
    {
        for(int j = 0 ; j<b_size-1-i ; j++)
        {
            if(b[j] > b[j+1]) swap(b[j],b[j+1]);
        }
    } 

    for(int i= 0 ; i<b_size ; i++)
    {
        cout << b[i] << " ";
    }
    

    return 0;
}
