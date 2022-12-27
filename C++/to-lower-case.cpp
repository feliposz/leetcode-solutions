class Solution {
public:
    string toLowerCase(string s) {
        int sz = s.length();
        for (int i = 0; i < sz; i++) {
            if (isupper(s[i]));
                s[i] =  tolower(s[i]);
        }
        return s;
    }
};