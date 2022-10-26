class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> count(nums.size() + 1);
        
        int dup = -1;
        
        for (int n: nums) {
            count[n]++;
            if (count[n] == 2) {
                dup = n;
            }
        }
        
        int missing = -1;
        for (int i = 1; i < count.size(); i++) {
            if (count[i] == 0) {
                missing = i;
                break;
            }
        }
        
        return {dup, missing};
    }
};