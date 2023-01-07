class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalCost = 0, totalGas = 0;
        for (int i = 0; i < n; i++) {
            totalCost += cost[i];
            totalGas += gas[i];
        }

        if (totalCost > totalGas) {
            return -1;
        }

        int index = 0;
        int tank = 0;
        for (int i = 0; i < n; i++) {
            tank = tank - cost[i] + gas[i];
            if (tank < 0) {
                index = i + 1;
                tank = 0;
            }
        }
        return index;
    }
};