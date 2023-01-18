class Solution {
public:
    int fib(int n) {
        int i = 0, j = 1;
        while (n--) {
            int k = i + j;
            i = j;
            j = k;
        }
        return i;
    }
};