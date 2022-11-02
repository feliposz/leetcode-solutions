class Solution {
public:
    int countTriples(int n) {
        int count = 0;
        int n2 = n*n;
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                for (int c = 1; c <= n; c++) {
                    int c2 = a*a + b*b;
                    if (c2 == c*c) {
                        count++;
                    }
                }
                
            }
        }
        return count;
    }
    
};