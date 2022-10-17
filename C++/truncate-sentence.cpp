class Solution {
public:
    string truncateSentence(string s, int k) {
        int words = 0;
        int i = 0;
        int sz = s.size();
        for (; i < sz; i++) {
            if (s[i] == ' ')
                words++;
                if (words == k) {
                    return s.substr(0, i);
                }
        }
        return s;
    }
};