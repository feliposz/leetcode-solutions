class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size();
        int m = l.size();
        vector<bool> ans(m);
        for (int i = 0; i < m; i++) {
            vector<int> tmp;
            ans[i] = true;
            
            for (int j = l[i]; j <= r[i]; j++) {
                tmp.push_back(nums[j]);
            }

            sort(tmp.begin(), tmp.end());
            
            int diff = tmp[1] - tmp[0];

            for (int j = 0; j < tmp.size() - 1; j++) {
                if (tmp[j+1] - tmp[j] != diff) {
                    ans[i] = false;
                    break;
                }
            }

        }
        return ans;
    }
};