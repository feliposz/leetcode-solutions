class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ans;
        
        int partial = 0;
        
        for (int p: pref) {
            int j = partial ^ p;
            ans.push_back(j);
            partial ^= j;
        }
        return ans;
    }
};