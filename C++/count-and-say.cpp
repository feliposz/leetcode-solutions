class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        
        while (n-- > 1) {
            string t;
            int sz = s.size();
            char digit = '?';
            int count = 0;
            int i = 0;
            for (; i < sz; i++) {
                if (digit == s[i]) {
                    count++;
                } else {
                    if (count > 0) {
                        t += (count + '0');
                        t += digit;
                    }
                    digit = s[i];
                    count = 1;
                }
            }
            if (count > 0) {
                t += (count + '0');
                t += digit;
            }
            s = t;
        }
        
        return s;
    }
};