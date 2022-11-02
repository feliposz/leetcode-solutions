class Solution {
public:
    int totalMoney(int n) {
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += 1 + i % 7 + i / 7;
        }        
        return total;
    }
};