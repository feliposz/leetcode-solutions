class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        set<string> ans;
        
        int sz = s.size();
        int pow = 1 << sz;
        for (int i = 0; i <= pow; i++) {
            string t;
            for (int j = 0; j < sz; j++) {
                if (i & (1 << j)) {
                    t += toupper(s[j]);
                } else {
                    t += tolower(s[j]);
                }
            }
            ans.insert(t);
        }
        
        vector<string> result(ans.begin(), ans.end());
        
        return result;
    }
};