class Solution {
public:
    string addStrings(string num1, string num2) {
        int sz1 = num1.size();
        int sz2 = num2.size();
        int i = sz1 - 1;
        int j = sz2 - 1;
        
        int carry = 0;
        vector<int> tmp;
        while (i >= 0 || j >= 0) {
            int sum = carry;
            if (i >= 0) {
                sum += num1[i] - '0';
                i--;
            }
            if (j >= 0) {
                sum += num2[j] - '0';
                j--;
            }
            tmp.push_back(sum % 10);
            carry = sum / 10;
        }
        
        if (carry > 0) {
            tmp.push_back(carry);
        }
        
        string s;
        
        while (tmp.size() > 0) {
            s += tmp.back() + '0';
            tmp.pop_back();
        }
        
        return s;
    }
};