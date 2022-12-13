class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        
        for (int n: nums) {
            freq[n]++;
        }
        
        vector<int> counts;
        
        for (auto it: freq) {
            counts.push_back(it.second);
        }
        
        sort(counts.begin(), counts.end());
        
        vector<int> ans;

        for (auto it: freq) {
            for (int i = 0; i < k; i++) {
                int c = counts[counts.size() - i - 1];
                if (it.second == c) {
                    ans.push_back(it.first);
                    break;
                }
            }
        }
        
        
        return ans;
    }
};