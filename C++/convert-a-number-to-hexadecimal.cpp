class Solution {
public:
    string toHex(int num) {
        vector<int> digits;
        
        if (num == 0) {
            return "0";
        }
        
        unsigned int n = (unsigned int) num;
        while (n) {
            digits.push_back(n % 16);
            n /= 16;
        }
        
        string s;
        
        while (digits.size()) {
            int d = digits.back();
            digits.pop_back();
            if (d >= 10) {
                s += 'a' + (d - 10);
            } else {
                s += '0' + d;
            }
        }
        
        return s;
    }
};