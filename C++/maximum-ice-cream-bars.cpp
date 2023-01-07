class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());

        int count = 0;
        for (int cost : costs) {
            if (cost <= coins) {
                count++;
                coins -= cost;
            }
        }

        return count;

        // return maxIceCream(costs, coins, 0, costs.size());
    }

    int maxIceCream(vector<int>& costs, int coins, int i, int n) {
        if (i < n) {
            int x = 0;
            if (costs[i] <= coins) {
                x = 1 + maxIceCream(costs, coins - costs[i], i + 1, n);
            }
            int y = maxIceCream(costs, coins, i + 1, n);
            return max(x, y);
        }
        return 0;
    }
};