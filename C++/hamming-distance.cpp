class Solution {
public:
    int hammingDistance(int x, int y) {
        int diff = x ^ y;
        int dist = 0;
        while (diff) {
            if (diff & 1) {
                dist++;
            }
            diff >>= 1;
        }
        return dist;
    }
};