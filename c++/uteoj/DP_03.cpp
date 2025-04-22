#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int n, l;
int main()
{
    cin >> n >> l;
    vector<int> word_lens(n);
    for (int i = 0; i < n; ++i) cin >> word_lens[i];


    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0; 

    for (int i = 1; i <= n; ++i) {
        int line_length = 0;
        
        for (int j = i; j >= 1; --j) {
            line_length += word_lens[j - 1];
            int spaces = i - j; 
            
            if (line_length + spaces > l) {
                break;
            }

            dp[i] = min(dp[i], dp[j - 1] + (l - (line_length + spaces)) * (l - (line_length + spaces)));
        }
    }

    cout << dp[n] << endl;
    return 0;
}
