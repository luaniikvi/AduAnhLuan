#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> getNum(string str, int length);

int main()
{
    int length;
    cin >> length;
    string temp;
    cin >> temp;
    string str;
    for(int i=0 ; i<length ;i++)
    {
        str += temp[i];
    }

    vector<int> num = getNum(str, length);

    int sum = 0;
    for(int &n : num)
    {
        sum+= n;
    }
    cout << sum;

    return 0;
}

bool isNum(char ch)
{
    return (ch >= '0' && ch <= '9');
}

int convToNum(string str)
{
    int num = 0;
    for(int i=0 ;i<str.length() ;i++)
    {
        num = num*10 + (str[i] -'0');
    }

    return num;
}

vector<int> getNum(string str, int length)
{
    vector<int> num;
    str+=" ";
    string temp = "";
    int dau =1;
    for(int i=0;i<=length;i++)
    {
        if(str[i] == '-') dau = -1;
        if(isNum(str[i]))
        {
            temp+=str[i];
        }
        else{
            if(temp == "") continue;
            num.push_back(convToNum(temp)*dau);
            temp = "";
            dau = 1;
        }
    }

    return num;
}