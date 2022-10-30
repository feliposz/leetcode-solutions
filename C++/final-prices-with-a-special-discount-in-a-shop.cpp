class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        
        vector<int> discounted;
        
        int sz = prices.size();
        
        for (int i = 0; i < sz; i++) {
            discounted.push_back(prices[i]);
            for (int j = i + 1; j < sz; j++) {
                if (prices[j] <= prices[i]) {
                    discounted[i] -= prices[j];
                    break;
                }
            }
        }
        
        return discounted;
    }
};