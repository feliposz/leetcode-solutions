class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int sz = bank.size();
        
        int prev = 0;
        
        int count = 0;
        
        for (int i = 0; i < sz; i++) {
            int lasers = 0;
            for (char c: bank[i]) {
                if (c == '1') {
                    lasers++;
                }
            }
            if (lasers > 0) {
                count += prev * lasers;
                prev = lasers;
            }
        }
        
        return count;
    }
};