class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ans = s;
        int sz = indices.size();
        for (int i = 0; i < sz; i++) {
            ans[indices[i]] = s[i];
        }            
        return ans;
    }
};