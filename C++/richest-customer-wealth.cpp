class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        long maxWealth = 0;
        
        for (auto &customer : accounts) {
            long wealth = 0;
            for (auto &bank : customer) {
                wealth += bank;
            }
            if (wealth > maxWealth) {
                maxWealth = wealth;
            }
        }
        
        return maxWealth;
    }
};