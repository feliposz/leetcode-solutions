class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        
        int sz2 = pattern.length();
        
        for (string &word: words) {
            int sz = word.length();
            if (sz == sz2) {
                bool match = true;
                map<char,char> m1;
                map<char,char> m2;
                for (int i = 0; i < sz; i++) {
                    if ((m1.count(pattern[i]) == 0) && (m2.count(word[i]) == 0)) {
                        m1[pattern[i]] = word[i];
                        m2[word[i]] = pattern[i];
                    }
                    if ((m1[pattern[i]] != word[i]) || (m2[word[i]] != pattern[i])) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    ans.push_back(word);
                }
            }
        }
        
        return ans;
    }
};