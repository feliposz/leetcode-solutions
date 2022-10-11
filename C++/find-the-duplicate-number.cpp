class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> count(nums.size());
        for (int n: nums) {
            if (++count[n] > 1) {
                return n;
            }
        }
        
        return -1;
    }
};