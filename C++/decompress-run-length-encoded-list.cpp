class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        int sz = nums.size();
        vector<int> ans;
        for (int i = 0; i < sz; i += 2) {
            int freq = nums[i];
            int val = nums[i+1];
            for (int j = 0; j < freq; j++) {
                ans.push_back(val);
            }            
        }
        return ans;
    }
};