class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        int carry = 0;
        int an = a.size();
        int bn = b.size();
        
        string c;
        int i = 0, j = 0;
        for (; (i < an) && (j < bn); i++, j++) {
            int digit = a[i] - '0' + b[j] - '0' + carry;
            c.push_back('0' + digit % 2);
            carry = digit / 2;
        }
        
        for (; i < an; i++) {
            int digit = a[i] - '0' + carry;
            c.push_back('0' + digit % 2);
            carry = digit / 2;
        }

        for (; j < bn; j++) {
            int digit = b[j] - '0' + carry;
            c.push_back('0' + digit % 2);
            carry = digit / 2;
        }

        if (carry)
            c.push_back('0' + carry);
        
        reverse(c.begin(), c.end());
        
        return c;
    }
};