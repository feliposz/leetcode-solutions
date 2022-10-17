class Solution {
public:
    string removeOuterParentheses(string s) {
        string t;
        int depth = 0;
        for (char c: s) {
            if (c == '(') {
                depth++;
                if (depth > 1) {
                    t += c;
                }
            } else if (c == ')') {
                depth--;
                if (depth > 0) {
                    t += c;
                }
            } else {
                t += c;
            }
        }
        return t;
    }
};