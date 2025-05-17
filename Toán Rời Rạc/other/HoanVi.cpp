#include"Func.h"
int main(){
    int n; cout << "Nhap kich thuoc cua tap hop: ";cin >> n; 
    vector<int> a(n);
    cout << "Nhap cac ptu: ";
    for(auto &in : a)
        cin >> in;
    
    cout << "Cac hoan vi cua tap hop:\n";
    Print(a);
    for(int i=0 ; i<Fac(n)-1 ; i++)
        Print(HoanVi(a));
    return 0;
}