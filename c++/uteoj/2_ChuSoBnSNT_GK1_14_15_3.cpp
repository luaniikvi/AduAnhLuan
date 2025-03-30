#include<iostream>
using namespace std;
int checkPrime(string str);

int main()
{
    string input;
    cin >> input;
    cout << checkPrime(input);
}

int checkPrime(string str)
{
    int count =0;
    int len = str.length();
    for(int i = 0; i<len ; i++)
    {
        if(str[i] == '2' || str[i] == '3' || str[i] == '5' || str[i] == '7')
        {
            count ++;
        }
    }
    return count;
}
