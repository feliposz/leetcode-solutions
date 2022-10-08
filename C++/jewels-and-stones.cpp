class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        char js[256];
        
        for (int i = 0; i < 256; i++) {
            js[i] = 0;
        }
        
        for (char j: jewels) {
            js[j] = 1;
        }
        
        int count = 0;
        for (char s: stones) {
            count += js[s];
        }
        
        return count;
    }
};