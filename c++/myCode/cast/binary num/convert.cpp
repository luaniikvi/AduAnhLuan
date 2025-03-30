#include<iostream>
using namespace std;

int BinaryToDecimal(int binary);

int main(){
    int binary;
    cout << "Input the binary: ";
    cin >> binary;

    cout << BinaryToDecimal(binary);

    return 0;
}


long long pow(int base,int power){
    if(power == 0 ) return 1;
    return base*pow(base,power-1);
}

int BinaryToDecimal(int binary){
    int decimal;
    int power = 0;
    while(binary!=0){
        decimal = (binary%10)*pow(2,power);
        binary/=10;power++;
    }

    return decimal;
}


auto _DecimalTo(int decimal,int newNumeral){
    string strNum="abc";
    int newNum = 0;

    if(newNumeral == 16){
    }
    else{
        while(decimal!=0){
            newNum = newNum*10 + decimal%newNumeral;
            decimal/=newNumeral;
        }
    }
    return ((newNumeral == 16) ? strNum : newNum);
}