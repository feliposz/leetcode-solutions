class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        set<int> present(nums.begin(), nums.end());

        int n = nums.size();
        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            if (present.count(i) == 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};