class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        combinationSum(candidates, target, 0, {}, 0, candidates.size());
        return ans;
    }

    void combinationSum(vector<int>& candidates, int target, int partial, vector<int> data, int i, int sz) {
        if (i >= sz) {
            return;
        }
        if (target == partial) {
            ans.push_back(data);
            return;
        }
        if (partial < target) {
            combinationSum(candidates, target, partial, data, i + 1, sz);
            if (partial + candidates[i] <= target) {
                data.push_back(candidates[i]);
                combinationSum(candidates, target, partial + candidates[i], data, i, sz);
            }
        }
    }
};