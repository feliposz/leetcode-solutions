class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int sz = nums.size();
        int count = 0;
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                if (nums[j] - nums[i] == diff) {
                    for (int k = j + 1; k < sz; k++) {
                        if (nums[k] - nums[j] == diff) {
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }
};