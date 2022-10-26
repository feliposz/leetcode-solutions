class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> pos;
        int sz = nums.size();
        for (int i = 0; i < sz; i++) {
            if ((pos.count(nums[i]) > 0) && abs(pos[nums[i]] - i) <= k) {
                return true;
            }
            pos[nums[i]] = i;
        }
        return false;
    }
};