class Solution {
public:
    int myAtoi(string s) {
        
        int i = 0, sz = s.size();
        
        while ((s[i] == ' ') && (i < sz)) {
            i++;
        }
        
        int sign = 1;
        
        if (s[i] == '+') {
            i++;
        } else if (s[i] == '-') {
            i++;
            sign = -1;
        }
        
        long val = 0;
        
        while (isdigit(s[i]) && (i < sz)) {
            val = val * 10 + (s[i] - '0');
            i++;
            
            if (val >= INT32_MAX)
                break;
        }
        
        val = sign * val;
        
        if (val < INT32_MIN) {
            val = INT32_MIN;
        }
        
        if (val > INT32_MAX) {
            val = INT32_MAX;
        }
        
        return val;
    }
};