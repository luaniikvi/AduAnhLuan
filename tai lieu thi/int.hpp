long long reverse(long long x)
{
    if (abs(x) < 10) return x;
    long long rev = 0;
    while (x != 0)
    {
        rev = rev * 10;
        rev += x % 10;
        x /= 10;
    }
    // overflow
    if (rev > INT_MAX || rev < INT_MIN)
        return 0;
    return rev;
}

// find the index of target after insert
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

// pascal pyramic C(n,k)
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    vector<int> prevRow;
    for(int i=0 ;i<numRows ; i++)
    {
        vector<int> currRow(i+1,1);
        for(int j=1 ; j<i ; j++)
            currRow[j] = prevRow[j-1] + prevRow[j];
        res.push_back(currRow);
        prevRow = currRow;
    }
    return res;
}

vector<long long> getRow(long rowIndex) {
    vector<long long> list;
    list.push_back(1);
    for(long i = 1; i <= rowIndex; i++){
        long res = list[i-1] * (rowIndex - i + 1) / i;
        list.push_back(res);
    }
    return list;
}