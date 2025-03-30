#include<iostream>
#include<sstream>
#include<string>
#include<bitset>
#include<vector>
using namespace std;

int main()
{
    [=]()
    {
      ios_base::sync_with_stdio(NULL);
      //cin.tie(NULL);
      cout.tie(NULL);  
    }();
    int decNum;
    cout << "Input the decNum: ";
    cin >> decNum;

    stringstream ss;
    ss << std::hex << decNum;

    cout << "hex: " << ss.str() << endl;
    stringstream sss;
    bitset<8> bit(decNum);
    sss << bitset<8>(decNum);

    cout << "binary: "<< sss.str();

    return 0;
}