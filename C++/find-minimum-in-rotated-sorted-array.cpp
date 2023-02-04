class Solution {
public:
    int findMin(vector<int>& nums) {
        int sz = nums.size();
        int i = 0, j = sz - 1;
        
        if (sz == 1) {
            return nums[0];
        }
        
        if (nums[i] < nums[j]) {
            return nums[i];
        }
        
        int min = nums[0];
        while (i < j) {
            int mid = (i + j) / 2;
            if (nums[mid] > nums[mid+1]) {
                return nums[mid+1];
            } else if (nums[mid-1] > nums[mid]) {
                return nums[mid];
            }
            if (nums[mid] > nums[i]) {
                i = mid;
            } else if (nums[mid] < nums[i]) {
                j = mid;
            }
        }
        return INT32_MAX;
    }
};