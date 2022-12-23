class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        int x1 = coordinates[0][0];
        int y1 = coordinates[0][1];

        int x2 = coordinates[1][0];
        int y2 = coordinates[1][1];
        
        double slope1 = (double)(x1 - x2) / (y1 - y2);

        int sz = coordinates.size();
        
        for (int i = 2; i < sz; i++) {
            x1 = x2;
            y1 = y2;
            x2 = coordinates[i][0];
            y2 = coordinates[i][1];
            
            double slope2 = (double)(x1 - x2) / (y1 - y2);

            if ((y1 != y2) && (fabs(slope1 - slope2) > 0.001)) {
                return false;
            }
            
            slope1 = slope2;
        }
        
        return true;
    }
};