class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int nearest = -1;
        int minDist = INT_MAX;
        int sz = points.size();
        for (int i = 0; i < sz; i++) {
            if (points[i][0] == x) {
                int dist = abs(points[i][1] - y);
                if (minDist > dist) {
                    minDist = dist;
                    nearest = i;
                }
            } else if (points[i][1] == y) {
                int dist = abs(points[i][0] - x);
                if (minDist > dist) {
                    minDist = dist;
                    nearest = i;
                }
            }
        }
        return nearest;
    }
};