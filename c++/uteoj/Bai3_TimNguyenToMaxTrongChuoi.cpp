#include<iostream>
#include<vector>
using namespace std;

bool isPrime(int n);
vector<int> GetNums(string str);

int main()
{
    string ori;
    getline(cin , ori);

    vector<int> nums = GetNums(ori);
    int _max = 0;
    for(int &num : nums)
    {
        if(isPrime(num)) _max = max(_max,num);
    }
    cout << _max;
    return 0;
}

vector<int> GetNums(string str)
{
    str += ' ';
    vector<int> nums;
    int temp = 0;
    for(char &c : str)
    {
        if(isdigit(c))
        {
            temp =  temp*10 + (c-'0');
        }
        else
        {
            nums.push_back(temp);
            temp = 0;
        }
    }
    return nums;
}

bool isPrime(int n)
{
    if(n<=1) return false;
    if(n<=3) return true;
    if( n%2 == 0 || n%3 == 0) return false;
    for(int i=5 ; i*i <= n ; i+=6)
    {
        if(n%i == 0 || n%(i+2) == 0) return false;
    }
    return true;
}