class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> tmp;
        
        long sz = nums.size();
        for (int i = 0; i < sz; i++) {
            long j = (sz - (k%sz) + i) % sz;
            tmp.push_back(nums[j]);
        }
        
        nums = tmp;
    }
};