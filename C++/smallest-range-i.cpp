class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int minN = *min_element(nums.begin(), nums.end());
        int maxN = *max_element(nums.begin(), nums.end());
        
        minN += k;
        maxN -= k;
        
        return minN > maxN ? 0 : maxN - minN;
    }
};