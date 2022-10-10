class Solution {
public:
    vector<int> minOperations(string boxes) {
        int sz = boxes.size();
        vector<int> ans(sz);        
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                ans[i] += abs(i - j) * (boxes[j] - '0');
            }
        }
        return ans;
    }
};