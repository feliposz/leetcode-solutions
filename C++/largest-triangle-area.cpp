class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxArea = 0;
        int sz = points.size();
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                for (int k = j + 1; k < sz; k++) {
                    double area = TriangleArea(
                        points[i][0], points[i][1], 
                        points[j][0], points[j][1], 
                        points[k][0], points[k][1]);
                    if (maxArea < area) {
                        maxArea = area;
                    }
                }
            }
        }
        return maxArea;
    }
    
    double TriangleArea(int x1, int y1, int x2, int y2, int x3, int y3) {
        return fabs(0.5 * (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)));
    }
};