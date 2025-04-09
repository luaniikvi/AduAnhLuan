#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
#define ll long long
ll ops[100005],dp[100005][17];
ll INF=1e17,n,k,x;

vector<ll> median(vector<int>& nums, int k) {
    multiset<ll> left, right;
    ll leftSum = 0, rightSum = 0;
    vector<ll> result;

    auto balance = [&]() {
        while (left.size() > right.size() + 1) {
            ll val = *left.rbegin();
            right.insert(val);
            rightSum += val;
            leftSum -= val;
            left.erase(prev(left.end()));
        }
        while (right.size() > left.size()) {
            ll val = *right.begin();
            left.insert(val);
            leftSum += val;
            rightSum -= val;
            right.erase(right.begin());
        }
    };

    auto getOperations = [&]() -> ll {
        ll median = *left.rbegin();
        return (median * (ll)left.size() - leftSum) + (rightSum - median * (ll)right.size());
    };

    for (ll i = 0; i < nums.size(); ++i) {
        ll num = nums[i];
        if (left.empty() || num <= *left.rbegin()) {
            left.insert(num);
            leftSum += num;
        } else {
            right.insert(num);
            rightSum += num;
        }
        balance();

        if (i >= k - 1) {
            result.push_back(getOperations());
            ll removeNum = nums[i - k + 1];
            if (left.find(removeNum) != left.end()) {
                left.erase(left.find(removeNum));
                leftSum -= removeNum;
            } else {
                right.erase(right.find(removeNum));
                rightSum -= removeNum;
            }
            balance();
        }
    }
    return result;
}


ll rec(ll i,ll sub){
    if(i>=n) return (sub>=k)?0:INF;
    if(dp[i][sub]!=-1) return dp[i][sub];
    dp[i][sub]=min(rec(i+x,sub+1)+ops[i],rec(i+1,sub));
    return dp[i][sub];
}

class Solution {
public:
    long long minOperations(vector<int>& nums, int X, int K) {
        n=nums.size(),k=K,x=X;
        int mini=*min_element(nums.begin(),nums.end());
        if(mini<0) for(int i=0;i<n;i++) nums[i]-=mini;
        vector<ll> pre(n+1,0);
        vector<ll> medians=median(nums,x);
        int j=0;
        for(int i=1;i<=n;i++) pre[i]=pre[i-1]+nums[i-1];
        for(int i=0;i<n;i++){
            if(i+x>n){
                ops[i]=INF;
                continue;
            }
            ops[i]=medians[j++];
        }
    
        for(int i=0;i<=n;i++) for(int j=0;j<=k;j++) dp[i][j]=-1;
        return rec(0,0);
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solution s;
    cin >> n >> x >> k;
    vector<int> a(n);
    for(auto &i : a) cin >> i;
    cout << s.minOperations(a,x,k);
    return 0;
}