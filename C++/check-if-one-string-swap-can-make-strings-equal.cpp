class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) {
            return true;
        } else {
            int sz = s1.size();
            int pos = -1;
            char c1 = 0, c2 = 0;
            for (int i = 0; i < sz; i++) {
                if (s1[i] != s2[i]) {
                    if (pos == -1) {
                        pos = i;
                        c1 = s1[i];
                        c2 = s2[i];
                    } else if (s2[i] == c1 && s1[i] == c2) {
                        c1 = 0;
                        c2 = 0;
                    } else {
                        return false;
                    }
                }
            }
            return c1 == 0;
        }
    }
};