class Solution {
public:
    int search(vector<int>& nums, int target) {
        int k = 0;
        int sz = nums.size();
        for (int i = 1; i < sz; i++) {
            if (nums[i-1] > nums[i]) {
                k = i;
                break;
            }
        }
        
        
        int i = 0, j = sz - 1;
        while (i <= j) {
            int mid = (i + j) / 2;
            int test = (mid + k) % sz;
            if (nums[test] == target) {
                return test;
            } else if (target < nums[test]) {
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        return -1;
    }
};