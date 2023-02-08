class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int sz = strs.size();
        int len = strs[0].length();
        int max = 0;
        for (int i = 0; i < len; i++) {
            int j = 1;
            for (; j < sz; j++) {
                if (strs[0][i] != strs[j][i]) {
                    break;
                }                    
            }       
            if (j < sz) {
                break;
            }
            max = i + 1;
        }
        return strs[0].substr(0, max);
    }
};