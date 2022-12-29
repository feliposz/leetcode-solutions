class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<char> vs(s.begin(), s.end());
        vector<char> vt(t.begin(), t.end());
        
        sort(vs.begin(), vs.end());
        sort(vt.begin(), vt.end());
        
        return vs == vt;
    }
};