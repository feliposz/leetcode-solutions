class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> result;
        
        for (vector<int> q: queries) {
            int qx = q[0];
            int qy = q[1];
            int qr = q[2];
            int count = 0;
            for (vector<int> p: points) {
                int px = p[0];
                int py = p[1];
                int dist2 = (px - qx) * (px - qx) + (py - qy) * (py - qy);
                if (dist2 <= (qr * qr)) {
                    count++;
                }
            }
            result.push_back(count);
        }
        
        return result;
    }
};