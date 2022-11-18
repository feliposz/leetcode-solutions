class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int sz = nums.size();
        if (sz == 1) {
            ans.push_back(to_string(nums[0]));
        } else if (sz > 1) {
            int start = nums[0], end = nums[0];
            for (int i = 1; i <= sz; i++) {
                if (i < sz && nums[i-1] + 1 == nums[i]) {
                    end = nums[i];
                } else {
                    if (start == end) {
                        ans.push_back(to_string(start));
                    } else {
                        ans.push_back(to_string(start) + "->" + to_string(end));
                    }
                    if (i < sz) {
                        start = end = nums[i];
                    }
                }
            }
        }
        return ans;
    }
};