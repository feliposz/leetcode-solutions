class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto start = lower_bound(nums.begin(), nums.end(), target);
        auto end = upper_bound(nums.begin(), nums.end(), target);
        if (start == end) {
            return {-1, -1};
        }
        int i = start - nums.begin();
        int j = end - nums.begin() - 1;
        return {i, j};
    }
};