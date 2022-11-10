class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for (int &n: nums) {
            n *= n;
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};