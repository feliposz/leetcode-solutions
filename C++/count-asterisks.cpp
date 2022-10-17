class Solution {
public:
    int countAsterisks(string s) {
        bool inside = true;
        int count = 0;
        for (char c: s) {
            if (inside && (c == '*')) {
                count++;
            } else if (c == '|') {
                inside = !inside;
            }
        }
        return count;
    }
};