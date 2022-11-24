class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hist;
        
        for (int n : nums) {
            hist[n]++;
        }
        
        int maxNum = INT32_MIN;
        int maxCount = 0;
        
        for (auto it : hist) {
            if (it.second > maxCount)
            {
                maxNum = it.first;
                maxCount = it.second;
            }
        }
        
        return maxNum;        
    }
};