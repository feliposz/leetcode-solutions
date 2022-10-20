class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int sz = nums.size();
        vector<int> ans(sz);
        int j = 0;
        for (int i = 0; i < sz; i++) {
            if (nums[i] > 0) {
                ans[j] = nums[i];
                j += 2;
            }
        }
        j = 1;
        for (int i = 0; i < sz; i++) {
            if (nums[i] < 0) {
                ans[j] = nums[i];
                j += 2;
            }
        }
        return ans;
    }
};