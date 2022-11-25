class Solution {
public:
    
    vector<string> readBinaryWatch(int turnedOn) {
        int max = 1 << 10;
        vector<string> ans;
        for (int i = 0; i < max; i++) {
            int bits = 0;
            for (int j = 0; j <= 10; j++) {
                int mask = 1 << j;
                if (i & mask) {
                    bits++;
                }
            }
            if (bits == turnedOn) {
                int hour = i / 64;
                int min = i % 64;
                if (hour < 12 && min < 60) {
                    ans.push_back(to_string(hour) + ":" + (min < 10 ? "0" : "") + to_string(min));
                }
            }
        }
        return ans;
    }
};