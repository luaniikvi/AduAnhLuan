#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> a = {4,3,2,1,0};
    int i = 0;
    a.erase(a.begin()+ i , a.begin() + i + 1);

    for(auto n : a){
        cout << n << " ";
    }
}