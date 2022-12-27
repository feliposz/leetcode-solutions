class Solution {
public:
    string freqAlphabets(string s) {
        int sz = s.size();
        string t;
        for (int i = 0; i < sz; i++) {
            if ((i + 2 < sz) && (s[i+2] == '#')) {
                t += ('a' + (s[i] - '0') * 10 + (s[i+1] - '0') - 1);
                i += 2;
            } else {
                t += s[i] - '0' - 1 + 'a';
            }
        }
        return t;
    }
};