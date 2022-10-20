class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int> prev = nums;
        
        while (prev.size() > 1) {
            int sz = prev.size();    
            vector<int> row;
            for (int i = 1; i < sz; i++) {
                row.push_back((prev[i-1] + prev[i]) % 10);
            }
            prev = row;
        }
        
        return prev[0];
    }
};