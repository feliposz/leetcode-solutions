class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        return combine(1, n, k);
    }
    
    vector<vector<int>> combine(int start, int end, int k) {
        vector<vector<int>> ans;
        
        if (k > 0) {
            for (int i = start; i <= end; i++) {
                for (vector<int> tmp: combine(i + 1, end, k - 1)) {
                    tmp.insert(tmp.begin(), i);
                    ans.push_back(tmp);
                }                
            }
        } else {
            ans.push_back({});
        }
        
        return ans;
    }
};