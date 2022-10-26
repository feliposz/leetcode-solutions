class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> indices;
        int sz = nums.size();
        for (int i = 0; i < sz; i++) {
            if (nums[i] == target) {
                indices.push_back(i);
            }
        }
        return indices;
    }
};