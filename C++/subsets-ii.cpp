class Solution {
public:
    set<vector<int>> ans;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        subsetsWithDup(nums, 0, nums.size(), {});
        vector<vector<int>> tmp(ans.begin(), ans.end());
        return tmp;
    }

    void subsetsWithDup(vector<int>& nums, int i, int sz, vector<int> tmp) {
        if (i == sz) {
            ans.insert(tmp);
            return;
        }
        subsetsWithDup(nums, i + 1, sz, tmp);
        tmp.push_back(nums[i]);
        subsetsWithDup(nums, i + 1, sz, tmp);
    }
};