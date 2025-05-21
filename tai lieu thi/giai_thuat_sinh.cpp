#include<bits/stdc++.h>
using namespace std;      
int a[30];
bool check[30];
int n,m;
void xuat(){
      for(int i = 0; i < n; i++) cout << a[i] << " ";
      cout << '\n';
}
//Sinh nhị phân
void sinhNP(int k){
      if (k == n){
            xuat();
            return;
      }
      for(int i = 0; i <= 1; i++){
            a[k] = i;
            sinhNP(k+1);
      }
}
//Sinh hoán vị
void sinhHV(int k){
      if (k > n){
            xuat();
            return;
      }
      for(int i = 1; i <= n; i++)
      if (!check[i]){
            a[k] = i;
            check[i] = true;
            sinhHV(k+1);
            check[i] = false; 
      }
}

void xuatCH(){
      for(int i = 1; i <= n; i++)
      if (check[a[i]]) cout << a[i] << " ";
      cout << '\n';
}
//Sinh chỉnh hợp không lặp
void sinhCH(int k){
      if (k > m){
            xuatCH();
            return;
      }
      for(int i = 1; i <= n; i++)
      if (!check[i]){
            a[k] = i;
            check[i] = true;
            sinhCH(k+1);
            check[i] = false;
      }
}
void solve(){
      n = 5;
      m = 3;
      sinhCH(1); //sinh chỉnh hợp 5 chập 3
      sinhHV(1); //sinh hoán vị 1 -> 5
      sinhNP(0); //sinh nhị phân có độ dài 5
}
signed main()
{
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
      int t = 1;
      if (t > 1) cin >> t;
      while(t--){
            solve();
      }
}