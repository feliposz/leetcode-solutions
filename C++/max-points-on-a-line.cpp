class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();

        if (n < 2) {
            return n;
        }
        
        int maxP = 0;

        for (int i = 0; i < n; i++) {
            map<pair<double, double>,int> lines;
            for (int j = i+1; j < n; j++) {                
                maxP = max(maxP, ++lines[line(points[i], points[j])]);
            }
        }

        return maxP + 1;

    }

    pair<double,double> line(vector<int> &a, vector<int> &b) {
        double dx = a[0] - b[0];
        double dy = a[1] - b[1];
        if (dx == 0) {
            return {INFINITY, a[0]};
        }
        double slope = dy / dx;
        double offset = b[1] - slope * b[0];
        return {rounder(slope), rounder(offset)};
    }

    double rounder(double x) {
        return round(x * 10000.0) / 10000.0;
    }
};