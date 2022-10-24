class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        set<pair<int,int>> points;
        for (vector<int> &circle: circles) {
            int x1 = circle[0];
            int y1 = circle[1];
            int r = circle[2];
            
            int r2 = r * r;
            
            for (int x2 = x1 - r; x2 <= x1 + r; x2++) {
                for (int y2 = y1 - r; y2 <= y1 + r; y2++) {
                    int d2 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
                    if (d2 <= r2) {
                        points.insert({x2, y2});
                    }
                }                
            }
        }
        return points.size();
    }
};