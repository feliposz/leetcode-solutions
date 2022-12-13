class Solution {
public:
    vector<int> orig;
    vector<int> data;
    
    Solution(vector<int>& nums) {
        orig = data = nums;
    }
    
    vector<int> reset() {
        data = orig;
        return data;
    }
    
    vector<int> shuffle() {
        int sz = data.size();
        for (int i = 0; i < sz; i++) {
            int j = rand() % sz;
            int t = data[i];
            data[i] = data[j];
            data[j] = t;
        }
        return data;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */