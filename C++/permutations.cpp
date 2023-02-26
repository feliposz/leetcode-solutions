class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> tmp(nums.begin(), nums.end());
        
        sort(tmp.begin(), tmp.end());
        
        vector<vector<int>> ans;
            
        do {
            ans.push_back(tmp);
        } while(next_permutation(tmp.begin(), tmp.end()));
        
        return ans;
    }
};