class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });
        int shots = 1;
        int end = points[0][1];
        for (auto p : points) {
            if (p[0] > end) {
                end = p[1];
                shots++;
            }
        }
        return shots;
    }
};