#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        if(target > nums.back()) return nums.size();
        else if(target < nums[0]) return 0;

        int l= 0;
        int r = nums.size();
        int mid;
        while(l < r)
        {
            mid = (l-r)/2 +r;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target)
            {
                l = mid+1;
            }
            else r = mid -1;
            l++;r--;
        }


        if(nums[mid] > target) return mid-1;
        else if(nums[mid] < target) return mid +1;
        return mid;
    }
};

int main()
{
    vector<int> a = {1};
    Solution s;
    cout << s.searchInsert(a,1) << endl;

}