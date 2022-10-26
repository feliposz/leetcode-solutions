class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        if (n % 2) {
            ans.push_back(0);
            n--;
        }
        while (n > 0) {
            ans.push_back(-n);
            ans.push_back(n);
            n -= 2;
        }
        return ans;
    }
};