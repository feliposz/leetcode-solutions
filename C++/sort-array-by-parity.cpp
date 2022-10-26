class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int sz = nums.size();
        vector<int> result(sz);
        
        for (int i = 0, j = 0, k = sz -1; i < sz; i++) {
            if (nums[i] % 2 == 0) {
                result[j++] = nums[i];
            } else {
                result[k--] = nums[i];
            }
        }
        
        return result;
    }
};