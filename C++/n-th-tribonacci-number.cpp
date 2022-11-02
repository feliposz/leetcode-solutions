class Solution {
public:
    int tribonacci(int n) {
        long t0 = 0;
        long t1 = 1;
        long t2 = 1;
        
        while (n-- > 0) {
            long tn = t0 + t1 + t2;
            t0 = t1;
            t1 = t2;
            t2 = tn;
        }
        return t0;
    }
};