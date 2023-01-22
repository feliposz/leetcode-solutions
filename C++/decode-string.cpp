class Solution {
public:
    string decodeString(string s) {
        string result;
        
        int sz = s.size();
        int k = 0;
        int depth = 0;
        int start = 0;
        
        for (int i = 0; i < sz; i++) {
            if (s[i] == '[') {
                depth++;
                if (depth == 1) {
                    start = i + 1;
                }
            } else if (s[i] == ']') {
                depth--;
                if (depth == 0) {
                    string sub = decodeString(s.substr(start, i - start));
                    while (k--) {
                        result += sub;
                    }
                    k = 0;
                }
            } else if (depth == 0) {
                if ((s[i] >= '0') && (s[i] <= '9')) {
                    k = (k * 10) + (s[i] - '0');
                } else {
                    result += s[i];
                }
            }
        }
        
        return result;
    }
};