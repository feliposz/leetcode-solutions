class Solution {
public:
    int removePalindromeSub(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        if (s == r) return 1;
        return 2;
    }
};