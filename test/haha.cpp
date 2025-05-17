#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<string> a(3,"haha");
    for(auto i : a) cout << i << endl;
    return 0;
}