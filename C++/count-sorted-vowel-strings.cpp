class Solution {
public:
    int countVowelStrings(int n) {
        return count(n, 5);
    }
    
    int count(int n, int v) {
        int sum = 0;
        if (n == 1) {
            return v;
        }
        for (int x = 1; x <= v; x++) {
            sum += count(n - 1, x);
        }
        return sum;
    }
};