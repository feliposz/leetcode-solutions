class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int maxLen = 0;
        for (vector<int> r: rectangles) {
            int len = min(r[0], r[1]);
            if (maxLen < len) {
                maxLen = len;
            }
        }
        
        int count = 0;
        for (vector<int> r: rectangles) {
            int len = min(r[0], r[1]);
            if (len >= maxLen) {
                count++;
            }
        }
        
        return count;
    }
};