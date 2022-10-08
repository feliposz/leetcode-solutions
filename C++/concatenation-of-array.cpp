class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> result(nums.size() * 2);
        
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            result[i] = result[i+n] = nums[i];
        }
        
        return result;
    }
};