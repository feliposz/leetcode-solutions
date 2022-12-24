class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sz = arr.size();
        int sum = 0;
        for (int len = 1; len <= sz; len += 2) {
            for (int i = 0; i < (sz - len + 1); i++) {
                for (int j = i; (j < sz) && (j < i + len); j++) {
                    sum += arr[j];
                }
            }
        }
        return sum;
    }
};