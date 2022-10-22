class Solution {
public:
    int percentageLetter(string s, char letter) {
        int count = 0;
        for (char c: s) {
            if (c == letter) {
                count++;
            }
        }
        return (1000 * count + 5) / (s.size() * 10);
    }
};