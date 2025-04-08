#include"_lib.h"
class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            if(target > nums.back()) return nums.size();
            else if(target < nums[0]) return 0;
            int l = 0, r = nums.size() - 1;
            int mid;
            while(l <= r)
            {
                mid = (l-r)/2 + r;
                if(nums[mid] == target) return mid;
                else if(nums[mid] < target)
                {
                    l = mid + 1;
                }
                else r = mid - 1; 
            }
            while(nums[r] > target) r++;
            return r+1;
        }
    };