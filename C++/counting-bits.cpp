class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for (int i = 0; i <= n; i++) {
            int count = 0;
            int value = i;
            while (value > 0) {
                if (value & 1) {
                    count++;
                }
                value >>= 1;
            }
            ans.push_back(count);
        }
        return ans;
    }
};