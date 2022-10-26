class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        map<int,int> freq;
        for (int n: nums) {
            freq[n]++;
        }
        
        int pairs = 0;
        int left = 0;
        for (auto f: freq) {
            if (f.second % 2) {
                left++;
            }
            pairs += f.second / 2;
        }
        
        return {pairs, left};
    }
};