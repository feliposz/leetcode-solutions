class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sz = digits.size();
        int carry = 1;
        vector<int> result;
        for (int i = 0; i < sz; i++) {
            int val = digits[sz - i - 1] + carry;
            carry = val / 10;
            result.push_back(val % 10);
        }
        if (carry) {
            result.push_back(carry);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};