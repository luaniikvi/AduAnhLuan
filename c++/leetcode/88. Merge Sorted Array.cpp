#include "_lib.h"
class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& b, int n) {
            vector<int> a = nums1;
            int i=0,j=0;
            int pos = 0;
            while(i<m && j<n)
            {
                if(a[i] < b[j])
                    nums1[pos++] = a[i++];
                else
                    nums1[pos++] = b[j++];
            }
            while(i<m) nums1[pos++] = a[i++];
            while(j<n) nums1[pos++] = b[j++];
        }
    };