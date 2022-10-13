class Solution {
public:
    int getSum(int a, int b) {
        if ((a < 0) && (b < 0)) {
            return -getSum(-a, -b);
        } else if (b < 0) {
            return -getSum(a, -b);
        } else {
            while (b-- > 0) {
                a++;
            }
            return a;
        }        
    }
};