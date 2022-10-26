class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
            
        for (int n = left; n <= right; n++) {
            int t = n;
            bool ok = true;
            while (t > 0) {
                int d = t % 10;
                if ((d == 0) || (n % d != 0)) {
                    ok = false;
                    break;
                }
                t /= 10;
            }
            if (ok) {
                ans.push_back(n);
            }
        }
        
        return ans;
    }
};