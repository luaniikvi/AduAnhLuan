// write a function determine the longest word in a sentence. The function should take a string as an argument and return the length of the longest word. A word is a sequence of characters separated by spaces. If the input string is empty, the function should return 0.
#include<iostream>
#include<string>
using namespace std;

string longestWord(string s)
{
    string word = "";
    string longestWord = "";
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == ' ')
        {
            if(word.length() > longestWord.length())
            {
                longestWord = word;
            }
            word = "";
        }
        else
        {
            word += s[i];
        }
    }

    if(word.length() > longestWord.length())
    {
        longestWord = word;
    }
    
    return longestWord;
}

int main()
{
    string str;
    getline(cin,str);

    cout << longestWord(str) << endl;
    return 0;
}