class Solution {
public:
    bool backspaceCompare(string s, string t) {
        char a[201];
        char b[201];
        int m = 0, n = 0;
        for (char c: s) {
            if (c == '#') {
                if (m > 0) {
                    m--;
                }
            } else {
                a[m++] = c;
            }
        }
        for (char c: t) {
            if (c == '#') {
                if (n > 0) {
                    n--;
                }
            } else {
                b[n++] = c;
            }
        }
        if (m == n) {
            for (int i = 0; i < m; i++) {
                if (a[i] != b[i]) {
                    return false;
                }
            }
            return true;
        } else {
            return false;    
        }        
    }
};