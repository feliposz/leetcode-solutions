class Solution {
public:
    int minimumSum(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        
        int minSum = INT32_MAX;
        
        do {
            int a = s[0] - '0';
            int b = s[1] - '0';
            int c = s[2] - '0';
            int d = s[3] - '0';
            
            int s1 = a + 100*b + 10*c + d;
            int s2 = a + 10*b + c + 10*d;
            int s3 = 100*a + 10*b + c + d;
            
            if (s1 < minSum) minSum = s1;
            if (s2 < minSum) minSum = s2;
            if (s3 < minSum) minSum = s3;
            
        } while (next_permutation(s.begin(), s.end()));
        
        return minSum;
    }
};