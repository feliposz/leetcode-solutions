class Solution {
public:
    double average(vector<int>& salary) {
        int low = salary[0];
        int high = salary[0];
        int sum = 0;
        int n = 0;
        for (int s: salary) {
            low = min(low, s);
            high = max(high, s);
            sum += s;
            n++;
        }
        sum = sum - high - low;
        return (double)sum / (n - 2);
    }
};