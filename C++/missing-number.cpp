class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int total = 0;
        for (int n : nums) {
            total += n;
        }
        
        int expected = (nums.size()) * (nums.size() + 1) / 2;
        
        return expected - total;
    }
};