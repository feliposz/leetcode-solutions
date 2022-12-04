class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int> seq;
        
        int sz = s.size();
        for (int i = 0; i <= sz - 10; i++) {
            string t = s.substr(i, 10);
            seq[t]++;
        }
        
        vector<string> ans;
        for (auto p: seq) {
            if (p.second > 1) {
                ans.push_back(p.first);
            }
        }
        return ans;
    }
};