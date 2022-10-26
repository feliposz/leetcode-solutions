class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        map<int, int> s;
        for (int n: nums) {
            s[n]++;
        }
        int sum = 0;
        for (auto p: s) {
            sum += p.second == 1 ? p.first : 0;
        }
        return sum;
    }
};