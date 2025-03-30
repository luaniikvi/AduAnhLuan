#include<iostream>

double abs(double x);
int main(){
    double x;
    std::cin >> x;
    x = abs(x);
    //std::cout << "x: " << x << std::endl;
    int y =1;
    while(y< x) y +=2;
    std::cout << y;
    return 0;
}
double abs(double x){
    if(x<0) return -x;
    return x;
}
