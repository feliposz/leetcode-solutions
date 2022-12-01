class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> groups;
        
        for (string &s: strs) {
            string k = s;
            sort(k.begin(), k.end());
            groups[k].push_back(s);
        }
        
        for (auto it: groups) {
            ans.push_back(it.second);
        }
        
        return ans;        
    }
};