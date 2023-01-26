class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        int k = 0;
        
        if (target <= nums[i]) {
            return i;
        }
        else if (target > nums[j]) {
            return j + 1;
        }
        
        while (i <= j) {
            k = (i + j) / 2;
            if (nums[k] == target) {
                return k;
            } else if (target < nums[k]) {
                j = k - 1;
            } else {
                i = k + 1;
            }
        }
        
        if (target > nums[k])
            return k + 1;
            
        return k;
    }
};