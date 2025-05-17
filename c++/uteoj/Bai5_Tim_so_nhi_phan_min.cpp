#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int> convToNum(vector<string> strVt);
int getMinPos(vector<int> intVt);
vector<string> getAllBinary(vector<string> stringInput);

int main()
{
    string input;
    vector<string> strVt;
    cin >> input;
    strVt.push_back(input);
    int n = input.size();
    for(int i =0; i<n-1 ; i++)
    {
        cin >> input;
        strVt.push_back(input);
    }
    // cout << endl;
    // for(string& str : strVt)
    //{
    //     for(int i =0; i <n ; i++)
    //     {
    //         cout << str[i] << "  ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    vector<string> allNum_str = getAllBinary(strVt);
    //for(string&str : allNum_str) cout << str << endl;
    vector<int> allNum_int = convToNum(allNum_str);
    int pos = getMinPos(allNum_int);

    //cout << "The number is: ";
    cout << allNum_str[pos];

    return 0;
}
int convToNum(string str)
{
    int num =0;
    for(char& ch : str)
    {
        num = num*10 + ch - 48;
    }
    return num;
}

vector<int> convToNum(vector<string> strVt)
{
    vector<int> intVt;
    for(string& str : strVt)
    {
        intVt.push_back(convToNum(str));
    }
    return intVt;
}

int getMinPos(vector<int> intVt)
{
    int pos = 0;
    int min = intVt[0];
    for(int i = 0 ; i<intVt.size() ; i++)
    {
        if(intVt[i] < min)
        {
            pos = i;
            min = intVt[i];
        }
    } 
    return pos;
}

vector<string> getAllBinary(vector<string> stringInput)
{
    vector<string> allBinary;
    // add hang
    for(string& str: stringInput)
    {
        allBinary.push_back(str);
    }
    // add cot
    int size = stringInput[0].size();
    string temp = "";
    for(int i =0 ; i<size ; i++)
    {
        for(string& str : stringInput)
        {
            temp += str[i];
        }
        allBinary.push_back(temp);
        temp = "";
    }

    //add 2 duong cheo
    int i = 0;
    for(string& str : stringInput)
    {
        temp += str[i];
        i++;
    }
    allBinary.push_back(temp);
    temp = "";
    i = size -1;
    for(string& str : stringInput)
    {
        temp += str[i];
        i--;
    }
    allBinary.push_back(temp);
    temp = "";
    return allBinary;
}
