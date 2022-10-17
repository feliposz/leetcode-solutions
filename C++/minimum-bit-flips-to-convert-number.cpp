class Solution {
public:
    int minBitFlips(int start, int goal) {
        unsigned int x = start ^ goal;
        int bits = 0;
        while (x) {
            if (x & 1) {
                bits++;
            }
            x >>= 1;
        }
        return bits;
    }
};