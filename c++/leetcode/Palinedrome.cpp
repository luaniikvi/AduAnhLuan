#include<iostream>
#include<string>
using namespace std;

class Solution
{
public:

};


bool isPalindrome(string str);

int main()
{
    [=]()
    {
        ios_base::sync_with_stdio(NULL);
        cout.tie(NULL);
    }();
    string str;
    cout << "Input the string: ";
    cin >> str;

    cout << (isPalindrome(str) ? "La chuoi palindrome" : "Kh phai chuoi palindrome");


    return 0;
}

bool isPalindrome(string str)
{
    int l = 0;
    int r = str.length()-1;

    while(l<=r)
    {
        if(str[l]!=str[r])
        {
            return false;
        }
        l++;
        r--;
    }

    return true;
}