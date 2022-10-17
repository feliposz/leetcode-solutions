class Solution {
public:
    string replaceDigits(string s) {
        int sz = s.length();
        for (int i = 1; i < sz; i += 2) {
            char c = s[i-1];
            int x = s[i] - '0';
            s[i] = c + x;
        }
        return s;
    }
};