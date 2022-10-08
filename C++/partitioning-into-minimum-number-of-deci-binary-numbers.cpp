class Solution {
public:
    int minPartitions(string n) {
        int max = 0;
        for (char c: n) {
            int d = c - '0';
            if (d > max) {
                max = d;
            }
        }
        return max;
    }
};