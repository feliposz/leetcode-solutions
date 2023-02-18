class Solution {
public:
    int memo[10000+1][12+1];
    
    int coinChange(vector<int>& coins, int amount, int current) {
        int result;
        if (amount == 0) {
            result = 0;
        } else if (current >= coins.size()) {
            result = INT32_MAX - 1;
        } else if (memo[amount][current] >= 0) {
            return memo[amount][current];
        } else if (coins[current] > amount) {
            result = coinChange(coins, amount, current + 1);
        } else {
            int take = 1 + coinChange(coins, amount - coins[current], current);
            int dont = coinChange(coins, amount, current + 1);
            result = min(take, dont);
        }
        memo[amount][current] = result;
        return result;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        memset(memo, -1, sizeof(memo));
        
        int result = coinChange(coins, amount, 0);
        
        if (result >= INT32_MAX - 1) {
            return -1;
        }
        return result;
    }
};