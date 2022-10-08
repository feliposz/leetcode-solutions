class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> result;
        int sz = nums.size();
        for (int i = 0; i < sz; i++) {
            int count = 0;
            for (int j = 0; j < sz; j++) {
                if (i != j) {
                    if (nums[j] < nums[i])
                        count++;
                }   
            }
            result.push_back(count);
        }
        return result;
    }
};