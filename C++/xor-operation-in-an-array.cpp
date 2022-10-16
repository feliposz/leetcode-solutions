class Solution {
public:
    int xorOperation(int n, int start) {
        int result = 0;
        for (int i = 0; i < n; i++) {
            int num = start + 2 * i;
            result ^= num;
        }
        return result;
    }
};