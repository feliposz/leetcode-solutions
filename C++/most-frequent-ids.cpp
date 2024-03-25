class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        int n = nums.size();
        vector<long long> result(n);
        
        unordered_map<int, long long> id_map;
        map<long long, set<int>> size_map;
        
        for (int i = 0; i < n; i++) {
            size_map[0].insert(nums[i]);
        }
        
        for (int i = 0; i < n; i++) {
            long long old_size = id_map[nums[i]];
            long long new_size = old_size + freq[i];
            id_map[nums[i]] = new_size;
            size_map[old_size].erase(nums[i]);
            if (size_map[old_size].size() == 0) {
                size_map.erase(old_size);
            }
            size_map[new_size].insert(nums[i]);
            result[i] = size_map.rbegin()->first;
        }
        
        return result;
    }
};