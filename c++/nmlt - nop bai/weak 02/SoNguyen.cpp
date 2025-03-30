#include<iostream>
#include<math.h>
#include<string>
#define ull unsigned long long

using namespace std;

ull convToDigit(string input);
ull TongCacPtu(string input);
double logbase2(ull input);
int findK(ull input);

int main(){
    
    string input;
    cin >> input;
    ull inputDigit = convToDigit(input);
    cout << input.size() << endl; // kick thuoc
    cout << TongCacPtu(input) << endl;
    cout << findK(inputDigit);

    return 0;
}

ull convToDigit(string input){
    ull sum = input[0] - 48;
    for(int i = 1 ; i<input.size() ; i++){
        sum = sum*10 + (input[i]-48);
    }
    return sum;
}
ull TongCacPtu(string input){
    ull sum =0;
    for(int i = 0 ; i< input.size() ; i++ ){
        sum += input[i] - 48;
    }
    return sum;
}

double logbase2(ull input){
    return log((double)input) / ((double)log(2));
}
int findK(ull input){
    if(logbase2(input) <1){
        return -1;
    }
    else{
        return floor(logbase2(input));
    }
}
