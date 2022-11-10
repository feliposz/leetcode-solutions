class Solution {
public:
    string makeGood(string s) {
        bool changed = true;
        
        while (true) {
            string t = removeBad(s);
            if (t == s) {
                return t;
            }
            s = t;
        }
    }
    
    string removeBad(string s) {
        string t;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (i < n - 1 && islower(s[i]) && isupper(s[i+1]) && s[i] == tolower(s[i+1])) {
                i++;
            } else if (i < n - 1 && isupper(s[i]) && islower(s[i+1]) && s[i] == toupper(s[i+1])) {
                i++;
            } else {
                t += s[i];
            }
        }
        return t;
    }
};