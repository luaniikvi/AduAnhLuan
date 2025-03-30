#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string Simplize(string str)
{
    str += ' ';
    int len = str.length();
    string sim = "";
    for(char c : str)
    {
        if(isalnum(c)) sim+=c;
        else if(c == ' ' && isalnum(sim.back())) sim+=c;
    }
    if(sim.back() == ' ') sim.pop_back();
    return sim;
}

string TheLongestWord(string str)
{
    string longest = "";
    string temp= "";
    for(char c : str)
    {
        if(c == ' ')
        {
            if(temp.length() > longest.length())
                longest = temp;
            temp = "";
        }
        else temp+= c;
    }
    if(temp.length() > longest.length())
        longest = temp;

    return longest;
}

int main()
{
    string str;
    getline(cin, str);
    cout << str << endl;    

    string rev = str;
    reverse(rev.begin(), rev.end());
    cout << rev << endl;

    for(char c : str)
    if(isupper(c)) cout << (char)c << endl;

    string sim = Simplize(str);
    cout << TheLongestWord(str) << endl;

    cout << sim << endl;


    return 0;
}