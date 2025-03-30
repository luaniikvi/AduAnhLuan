#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// 4 4 12 32 34 90 1 31 30 5 4 33 20 44 3 34 35 23 --> 1 \n 2 2


vector<int> getRow(vector<vector<int>> matrix,int pos);
vector<int> getColumn(vector<vector<int>> matrix,int pos);
vector<int> getRow(vector<vector<int>> matrix,int pos);
vector<int> getColumn(vector<vector<int>> matrix,int pos);
int getMaxIn(vector<int> vt);
int getMinIn(vector<int> vt);
int main(){
    int m,n;
    cin >> m >> n;

    vector<vector<int>> matrix(m,vector<int>(n));
    for(int i = 0; i<m;i++){
        for(int j = 0 ; j<n ; j++){
            cin >> matrix[i][j];
        }
    }

    // xuat matrix
    // std::cout << "Ma tran vua nhap:" << std::endl;
    // for (int i = 0; i < m; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //         std::cout << matrix[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
    // cout << "----------------" << endl;
    vector<vector<int>> pos_yen;
    for(int i = 0; i<m;i++){
        for(int j = 0 ; j<n ; j++){
            vector<int> hang = getRow(matrix,i);   
            vector<int> cot = getColumn(matrix,j);
            if(matrix[i][j] == getMaxIn(hang) && matrix[i][j] == getMinIn(cot)){
                vector<int> temp(2);
                temp[0] = i+1;
                temp[1] = j+1;
                pos_yen.push_back(temp);
                //temp.clear();
            }
        }
    }

    if(pos_yen.empty()){
        cout << 0;
    }
    else{
        cout << pos_yen.size() << endl;
        for(vector<int> pos: pos_yen){
            for(int p : pos){
                cout << p <<" ";
            }
            cout << endl;
        }
    }

    return 0;
}

vector<int> getRow(vector<vector<int>> matrix,int pos){
    return matrix[pos];
}

vector<int> getColumn(vector<vector<int>> matrix,int pos){
    vector<int> cot;
    for(vector<int> hang : matrix){
        cot.push_back(hang[pos]);
    }
    return cot;
}

int getMaxIn(vector<int> vt){
    return *max_element(vt.begin(),vt.end());
}

int getMinIn(vector<int> vt){
    return *min_element(vt.begin(),vt.end());
}