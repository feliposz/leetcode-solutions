class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (int &n: nums) {
            if (((n >= 100000) && (n <= 999999)) ||
                ((n >= 1000) && (n <= 9999)) ||
                ((n >= 10) && (n <= 99))) {
                count++;
            }
        }
        return count;
    }
};