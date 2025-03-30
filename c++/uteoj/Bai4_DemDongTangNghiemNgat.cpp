#include<iostream>
#include<vector>
using namespace std;

int countTang(vector<vector<int>> matran,int cot);

int main(){
    vector<vector<int>> a; // matran A co kich thuoc m x n
    int m,n;
    cin >> m >> n;
    int input;
    vector<int> inputVt;

    for(int i=0; i<m ; i++){
        for(int j=0; j<n ; j++){
            cin >> input;
            inputVt.push_back(input);
        }
        a.push_back(inputVt);
        inputVt.clear();
    }

    //test matran
    // for(vector<int>& vtn : a){
    //     for(int& i : vtn){
    //         cout << i <<"  ";
    //     }
    //     cout << endl;
    // }

    cout << "so dong tang: ";
    cout << countTang(a,n);

    return 0;
}

bool tangNghiemNgat(vector<int> intVt,int col){
    for(int i=0 ; i< col-1 ; i++){
        if(intVt[i] >= intVt[i+1]){
            return false;
        }
    }
    return true;
}
int countTang(vector<vector<int>> matran,int cot){
    int count =0;
    for(vector<int> intvt : matran){
        if(tangNghiemNgat(intvt,cot)) count ++;
    }
    return count;
}

