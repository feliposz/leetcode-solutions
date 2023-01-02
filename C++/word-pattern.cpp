class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int sz = s.size();
        int p = 0;
        map<char,string> m;
        map<string,char> r;
        string word;
        for (int i = 0; i <= sz; i++) {
            if (i == sz || s[i] == ' ') {
                if (m.count(pattern[p]) || r.count(word)) {
                    if (m[pattern[p]] != word || r[word] != pattern[p]) {
                        return false;
                    }
                } else {
                    m[pattern[p]] = word;
                    r[word] = pattern[p];
                }
                p++;
                word = "";
            } else {
                word += s[i];
            }
        }
        return p == pattern.size();
    }
};