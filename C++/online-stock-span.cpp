class StockSpanner {
public:
    vector<int> prices;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        prices.push_back(price);
        for (int i = prices.size() - 1; i >= 0; i--) {
            if (prices[i] > price) {
                return prices.size() - i - 1;
            }
        }
        return prices.size();
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */