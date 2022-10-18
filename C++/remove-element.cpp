class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int sz = nums.size();
        
        for (int i = 0; i < sz; i++) {
            if (nums[i] == val) {
                nums[i] = nums[--sz];
                i--;
            }
        }
        
        return sz;
    }
};