#include<iostream>

int main(){
    int n;
    std::cin >> n;
    int MyArr[100];
    int count = 0;

    for(int i = 0 ; i<n ; i++){
        std::cin >> MyArr[i];
    }

    for(int j = 1 ; j < n; j++){
        if(MyArr[j] == MyArr[j-1] && MyArr[j] != MyArr[j+1] ){
            count++;
        }

    }
    std::cout << count;

    return 0;
}