class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> unique(nums.begin(), nums.end());
        
        int ans = -1;
        int count = 3;
        for (auto it = unique.rbegin(); it != unique.rend() && count > 0; it++, count--) {
            ans = *it;   
        }
        
        if (unique.size() < 3) {
            return *unique.rbegin();
        }
        return ans;
    }
};