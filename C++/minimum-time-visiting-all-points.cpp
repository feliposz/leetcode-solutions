class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int sz = points.size();
        
        int x1 = points[0][0];
        int y1 = points[0][1];
        
        int time = 0;
        
        for (int i = 1; i < sz; i++) {
            int x2 = points[i][0];
            int y2 = points[i][1];
            
            int dx = abs(x1 - x2);
            int dy = abs(y1 - y2);
            
            int d = dx > dy ? dx : dy;
            
            time += d;
            
            x1 = x2;
            y1 = y2;
        }
        
        return time;
    }
};