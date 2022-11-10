class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int x = 0;
        for (int i = 0; i < n; i++) {
            x ^= nums[i];
        }
        
        int mask = 1 << maximumBit;
        
        vector<int> ans;
        
        for (int i = n - 1; i >= 0; i--) {
            //int maxVal = x;
            //int maxK = 0;
            int maxK = x ^ (mask - 1);
            /*
            for (int k = 0; k < mask; k++) {
                if (maxVal < (x ^ k)) {
                    maxVal = x ^ k;
                    maxK = k;
                }
            }
            */
            ans.push_back(maxK);
            x ^= nums[i];
        }
        
        return ans;
    }
};