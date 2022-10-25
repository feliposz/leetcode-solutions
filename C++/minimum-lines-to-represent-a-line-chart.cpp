class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        int sz = stockPrices.size();
        
        sort(stockPrices.begin(), stockPrices.end());
        
        if (sz < 2) {
            return 0;
        }
        
        long x1 = stockPrices[0][0];
        long y1 = stockPrices[0][1];
        long x2 = stockPrices[1][0];
        long y2 = stockPrices[1][1];
        
        long lines = 1;
        
        for (int i = 2; i < sz; i++) {
            long x3 = stockPrices[i][0];
            long y3 = stockPrices[i][1];
            
            long d1 = (x2 - x1) * (y3 - y2);
            long d2 = (x3 - x2) * (y2 - y1);
            
            if (d1 != d2) {
                lines++;
            }
            
            x1 = x2;
            y1 = y2;
            x2 = x3;
            y2 = y3;
        }
        
        return lines;
    }
};