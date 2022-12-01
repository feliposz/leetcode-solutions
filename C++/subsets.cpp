class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int pow2 = pow(2, nums.size());
        
        vector<vector<int>> ans;
        
        for (int mask = 0; mask < pow2; mask++) {
            vector<int> subset;
            int bit = 1;
            for (int i = 0; i < nums.size(); i++) {
                if (bit & mask) {
                    subset.push_back(nums[i]);
                }
                bit <<= 1;
            }
            ans.push_back(subset);
        }
        
        return ans;
    }
};