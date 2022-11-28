class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size();
        vector<int> ans;
        long prod = 1;
        for (int j = 0; j < sz; j++) {
            prod *= nums[j];    
        }
        for (int i = 0; i < sz; i++) {
            if (nums[i] == 0) {
                int p = 1;
                for (int j = 0; j < sz; j++) {
                    if (i != j)
                        p *= nums[j];    
                }
                ans.push_back(p);
            } else {
                ans.push_back((int)(prod / nums[i]));    
            }         
        }
        return ans;
    }
};