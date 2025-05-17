#include<iostream>
#include<bits/stdc++.h>

bool isValid(int d, int m, int y);
void printNextDay(int d,int m,int y);

int main(){
    int d,m,y;
    std::cin >> d >> m >> y; 
    if(!isValid(d,m,y)){
        std::cout << 0;
        return 0;
    }
    printNextDay(d,m,y);

    return 0;
}
bool checkLeap(int year){
    return (year %400 == 0 ||(year%4==0 && year&100 != 0));
}
int getMaxDay(int m,int y){
    const int maxDay[13] ={31,31,0 ,31,30,31,30,31,31,30,31,30,31};
    if(m == 2){
        return (checkLeap(y) ? 29 : 28);
    }
    return maxDay[m];
}

bool isValid(int d, int m, int y){
    if(m > 12) return false;
    if(d > getMaxDay(m,y)) return false;
    return true;
}

void printNextDay(int d,int m,int y){
    d++;
    if(d > getMaxDay(m,y)) d = 1;
    std::cout << d;
}