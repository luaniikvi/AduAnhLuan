#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str;
    getline(cin,str);

    while(str[0] == ' ')
    {
        str.erase(str.begin(),str.begin()+1);
    }
    while(str.back() == ' ')
    {
        str.pop_back();
    }

    //int i = 0;
    string nor = "";
    for(int i = 0 ; i<str.size() ;i++)
    {
        if(isalpha(str[i])) nor+= str[i];
        if(str[i] == ' ' && isalpha(str[i-1])) nor+=str[i];
    }
    cout << nor;
    return 0;
}