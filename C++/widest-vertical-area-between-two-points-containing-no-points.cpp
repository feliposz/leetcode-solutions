class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int maxWidth = 0;
        int sz = points.size();
        for (int i = 1; i < sz; i++) {
            int width = points[i][0] - points[i-1][0];
            if (maxWidth < width) {
                maxWidth = width;
            }
        }
        return maxWidth;
    }
};