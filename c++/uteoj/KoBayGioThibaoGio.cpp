#include<iostream>
#include<queue>
#define _size 1000000
using namespace std;
int minOperationsToAllOnes(const string &S, int k, int n) {
    int res = 0;
    queue<int> flipQueue;
    int currentFlips = 0;

    for (int i = 0; i < n; ++i) {
        // Remove flips that are no longer affecting the current position
        while (!flipQueue.empty() && flipQueue.front() <= i - k) {
            flipQueue.pop();
            currentFlips--;
        }

        // Determine the current state of S[i]
        int currentState = S[i] - '0';
        if (currentFlips % 2 != 0) {
            currentState ^= 1;
        }

        // If the current bit is '0', perform a flip operation
        if (currentState == 0) {
            if (i + k > n) {
                return -1;  // Cannot perform the flip operation
            }
            res++;
            currentFlips++;
            flipQueue.push(i);
        }
    }

    return res;
}
int main()
{   
    int n, k; cin >> n >> k;
    char s[_size];
    for(int i=0 ; i<n ; i++)
        cin >> s[i];

    cout << minOperationsToAllOnes(s,k,n);    
    return 0;
}
