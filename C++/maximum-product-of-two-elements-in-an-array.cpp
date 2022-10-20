class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int sz = nums.size();
        int max = INT32_MIN;
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                int prod = (nums[i]-1) * (nums[j]-1);
                if (max < prod) {
                    max = prod;
                }
            }
        }
        return max;
    }
};