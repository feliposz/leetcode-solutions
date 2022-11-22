class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int r = 0;
        for (int i = 0; i < 32; i++) {
            r = (r << 1) | (n & 1);
            n >>= 1;
        }
        return r;
    }
};