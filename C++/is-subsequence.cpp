class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;
        
        while (s[i] && t[j]) {
            if (s[i] == t[j])
            {
                i++;
            }
            j++;
        }
        
        return s[i] == '\0';        
    }
};