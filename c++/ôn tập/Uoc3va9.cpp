#include<iostream>
#include<cmath>
#include <climits>
using namespace std;
int d3 = 0 , d9 = 0;

bool isPrime(long long k) {
    if (k <= 1) return false;
    if (k == 2 || k == 3) return true;
    if (k % 2 == 0 || k % 3 == 0) return false;
    for (long long i = 5; i * i <= k; i = i + 6) {
        if (k % i == 0 || k % (i + 2) == 0) return false;
    }
    return true;
}

bool co9uoc(long n){
    if(n<=0) return false;

    long eighth_root = round(sqrt(sqrt(n))) ;
    if(pow(eighth_root,8) == n && isPrime(eighth_root)) return true;

    long sqrt_n = int(sqrt(n));
    if(sqrt_n * sqrt_n != n ) return false;

    long divisors_of_sqrt_n = 0;
    for(int i=1 ; i<int(sqrt(sqrt_n))+1 ; ++i){
        if(sqrt_n % i == 0)
        {
            if(i*i == sqrt_n) divisors_of_sqrt_n+=1;
            else divisors_of_sqrt_n+=2;
        }
    }

    return divisors_of_sqrt_n==4;
}

bool co3uoc(long n_long) {
    if (n_long <= 1) return false;
    long long n = n_long;

    long long root_n = round(sqrt(n));

    if (root_n * root_n != n) {
        return false;
    }
    return isPrime(root_n);
}

int main()
{
    //long l,r; cin >> l >> r;

    for(long i=10 ; i<=50 ; i++)
        if(co3uoc(i)) d3++;
        else if(co9uoc(i)) d9++;
    cout << d3 << ' ' << d9;
}
