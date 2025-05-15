#include<iostream>
#include<cmath>
using namespace std;
int d3 = 0 , d9 = 0;
bool co3uoc(long n)
{
    if(sqrt(n) != int(sqrt(n))) return false;
    for(long i=2 ; i<sqrt(n) ; i++)
        if(n%i == 0) return false;
    return true;
}

bool co9uoc(long n)
{
    for(long u = 2; u * u * u * u <= n; ++u) {
        if(n % u != 0) continue;
        long a = n / u;
        if(a % u != 0) break;
        a /= u;
        long mid = sqrt(a);
        bool is_prime = 1;
        for(long x = 2; x * x <= mid; ++x) if(mid % x == 0) is_prime = 0;
        if(mid != u && mid * mid == a && is_prime) return true;
        break;
    }
    long x = 2;
    while(x * x * x * x * x * x * x * x < n) ++x;
    bool is_prime = 1;
    for(long i = 2; i * i <= x; ++i) if(x % i == 0) is_prime = 0;
    return (is_prime && x * x * x * x * x * x * x * x == n);
}

// Helper function to check if a number is prime
bool isPrime(long long k) {
    if (k <= 1) return false;
    if (k == 2 || k == 3) return true;
    if (k % 2 == 0 || k % 3 == 0) return false;
    for (long long i = 5; i * i <= k; i = i + 6) {
        if (k % i == 0 || k % (i + 2) == 0) return false;
    }
    return true;
}

bool hasNineDivisorsFast(long n_long) {
    if (n_long <= 0) return false;
    if (n_long == 1) return false; 

    long long n = n_long; 

    long p_limit_case1 = 0;
   
    if (sizeof(long) == 4) {
        p_limit_case1 = 15; 
    } else { 
        p_limit_case1 = 250; 
    }
    
    for (long p_base = 2; p_base <= p_limit_case1; ++p_base) {
        if (p_base > n && n > 0 && p_base > 1) { 
             if (p_base > 1 && n / p_base < p_base && n > 0 ) break;
        }
        
        if (!isPrime(p_base)) {
            continue;
        }
        
        long long current_val = 1;
        bool term_overflow_or_exceeded_n = false;
        for(int i = 0; i < 8; ++i) {
            if (p_base == 0) { current_val = 0; break; }
            if (p_base == 1) { current_val = 1; break; }

            if (current_val > 0 && p_base > 0 && current_val > 9223372036854775807LL / p_base) { // Max long long
                term_overflow_or_exceeded_n = true; 
                break;
            }
            current_val *= p_base;
            if (current_val > n && n > 0) { 
                 term_overflow_or_exceeded_n = true;
                 break;
            }
             if (current_val <= 0 && p_base > 1 && i<7) {
                term_overflow_or_exceeded_n = true;
                break;
            }
        }

        if (!term_overflow_or_exceeded_n && current_val == n) {
            return true;
        }
        
        if (term_overflow_or_exceeded_n && p_base > 1) {
            long double est_root8_n = 0;
            if (n > 0) est_root8_n = pow((long double)n, 1.0L/8.0L);
            if (p_base > est_root8_n + 2.0L && p_base > 5 && n > 0) { 
                break;
            }
            if (current_val > n && n > 0 && ! (current_val == 0 && term_overflow_or_exceeded_n) ) break;


        }
    }
    
 
    if (n < 36) return false; 

    long long root_n_val_ll = round(sqrt((long double)n)); 
    if (root_n_val_ll * root_n_val_ll == n) {
        long long m = root_n_val_ll; 
        
        if (m > 5) { 
            for (long long p1_cand = 2; p1_cand * p1_cand <= m; ++p1_cand) {
                if (m % p1_cand == 0) { 
                    if (isPrime(p1_cand)) {
                        long long p2_cand = m / p1_cand;
                        if (p2_cand != p1_cand && isPrime(p2_cand)) {
                            return true;
                        }
                    }
                }
            }
        }
    }

    return false;
}


bool hasThreeDivisorsFast(long n_long) {
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
