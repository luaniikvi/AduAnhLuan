#include <iostream>
#include <vector>
using namespace std;


int main(){
    [=](){
        ios_base::sync_with_stdio(0);
        //cin.tie(0);
        cout.tie(0);
    }(); // kh cần để ý dòng này

    int n,dem5=0,dem2 =0;
    //cout << "nhap n: ";
    cin >> n; // nhập số lượng dãy số
    int a; // lưu giá trị input từ bàn phím

    for(int i=0 ; i<n ; i++){
        cin >> a;
        if(a == 0) continue; // nếu a = 0 thì bỏ qua
        while(a%5 == 0) // phân tích nguyến số 5 nếu a chia hết
        {
            a/=5;
            dem5++;
        }
        while(a%2 == 0) // phân tích số nguyên tố 2 tương tự
        {
            a/=2;
            dem2++;
        }
    }
    // in ra biến đếm nhỏ hơn như đã giải thích trong file
    cout << min(dem2,dem5); // hàm min này muốn dùng thì
                            // #include<algorithm>
    return 0;
}