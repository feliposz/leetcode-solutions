class Solution {
public:
    int countSegments(string s) {
        int i = 0;
        int sz = s.size();
        int segments = 0;
        while (i < sz) {
            if (s[i] == ' ') {
                i++;
            } else {
                segments++;
                while (i < sz && s[i] != ' ') {
                    i++;
                }
            }            
        }
        return segments;
    }
};