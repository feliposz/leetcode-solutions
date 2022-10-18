class Solution {
public:
    int lengthOfLastWord(string s) {
        int lastSpace = 0;
        int sz = s.length();
        while (s[sz-1] == ' ') sz--;
        for (int i = 0; i < sz; i++) {
            if (s[i] == ' ') {
                lastSpace = i + 1;
            }
        }
        return sz - lastSpace;
    }
};