class Solution {
public:
    string reverseWords(string s) {
        int pos = 0, sz = s.size();
        for (int i = 0; i <= sz; i++) {
            if ((s[i] == ' ') || (i == sz)) {
                int a = pos;
                int b = i - 1;
                while (a < b) {
                    char tmp = s[a];
                    s[a] = s[b];
                    s[b] = tmp;
                    a++;
                    b--;
                }
                pos = i + 1;
            }
        }
        return s;
    }
};