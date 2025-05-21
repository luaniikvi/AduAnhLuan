//                       _oo0oo_
//                      o8888888o
//                      88" : "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \|     |// '.
//                 / \|||  :  |||// \
//                / _||||| -:- |||||- \
//               |   | \  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====

//                       `=---='
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define file(name) freopen(name".inp","r",stdin); freopen(name".out","w",stdout);

using namespace std;

void print_min(long n){

    int m = -1,k = -1;
    for(long i=1 ; i*i<= n ;i++){
        if(n%i == 0){
            if((i + n/i) %2 == 0 &&( n/i - i) % 2 == 0){
                m = (i+n/i)/2;
                k = (n/i-i)/2;
                break;
            }
        }
    }
    if(m == -1) cout << -1 << endl;
    else cout << m << ' ' << k << endl;
}

int main()
{
    faster;
    //file("task");
    long n=1000000000;cin >> n;
    print_min(n);

    return 0;
}