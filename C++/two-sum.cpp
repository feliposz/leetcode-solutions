class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> solution;
        int sz = nums.size();
        for (int i = 0; i < sz - 1; i++) {
            int rest = target - nums[i];
            for (int j = i + 1; j < sz; j++) {
                if (nums[j] == rest) {
                    solution.push_back(i);
                    solution.push_back(j);
                    break;
                }
            }
        }
        return solution;
    }
};