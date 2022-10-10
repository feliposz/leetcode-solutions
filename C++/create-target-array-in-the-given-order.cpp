class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int sz = nums.size();
        vector<int> ans;
        
        for (int i = 0; i < sz; i++) {
            auto it = ans.begin();
            ans.insert(it + index[i], nums[i]);
        }
        
        return ans;
    }
};