#include <iostream>
using namespace std;

int main(){
    try
    {
        string a = "abc";
        cout << a[-1];
    }
    catch(const std::exception& e)
    {
        cout << e.what() << '\n';
    }
    
}