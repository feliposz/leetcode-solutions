class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = INT32_MAX;
        int max = 0;
        
        for (int p: prices) {
            if (p < min) {
                min = p;
            }
            int profit = p - min;
            if (profit > max) {
                max = profit;
            }
        }
        
        return max;
    }
};