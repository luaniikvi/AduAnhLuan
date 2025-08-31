#include <iostream>
#include <algorithm>

using namespace std;

main(){
    double temp[] = {3.0,5.0,4.9};
    sort(temp,temp+3);
    for(int i=0 ; i< 3 ; i++) cout << temp[i] << " ";
}