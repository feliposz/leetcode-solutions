class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char,int> a;
        for (char c: s) {
            a[c]++;
        }
        for (char c: t) {
            a[c]--;
        }
        
        for (auto p: a) {
            if (p.second != 0) {
                return p.first;
            }
        }
        return '\0';
    }
};