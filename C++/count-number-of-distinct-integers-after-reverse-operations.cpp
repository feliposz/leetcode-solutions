class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        set<int> distinct;
        for (int n: nums) {
            distinct.insert(n);
            int x = 0;
            while (n > 0) {
                x = x * 10 + n % 10;
                n /= 10;
            }
            distinct.insert(x);
        }
        return distinct.size();
    }
};