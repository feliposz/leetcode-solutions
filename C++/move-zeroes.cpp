class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 1, sz = nums.size();
        
        while (j < sz) {
            if (nums[i] == 0) {
                if (nums[j] != 0) {
                    nums[i] = nums[j];
                    nums[j] = 0;
                    i++;
                    j++;
                }
                else {
                    j++;
                }
            }
            else {
                i++;
                j++;
            }
        }
    }
};