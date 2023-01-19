class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int sz = cost.size();
        vector<int> step(sz);
        step[0] = cost[0];
        step[1] = cost[1];
        for (int i = 2; i < sz; i++) {
            step[i] = cost[i] + min(step[i-1], step[i-2]);
        }
        return min(step[sz-1], step[sz-2]);
    }
};