#include <iostream>
using namespace std;

int main(){
    long long a,b,c;
    cin >> a >> b >>c;
    if(a+b>c && b+c>a && a+c>b) cout << "YES";
    else cout << "NO";

    return 0;
}