class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        set<pair<int,int>> p;
        
        for (auto &point: points) {
            p.insert({point[0], point[1]});
        }
        
        int minArea = INT32_MAX;
        
        for (auto &p1: p) {
            for (auto &p2: p) {
                if (p1 != p2) {
                    int x1 = p1.first;
                    int y1 = p1.second;
                    int x2 = p2.first;
                    int y2 = p2.second;
                    if ((x1 < x2) && (y1 < y2)) {
                        if (p.count({x1,y2}) && p.count({x2,y1})) {
                            int area = (x2 - x1) * (y2 - y1);
                            if (minArea > area) {
                                minArea = area;
                            }
                        }
                    }
                }
            }
        }
        
        if (minArea == INT32_MAX) {
            minArea = 0;
        }
            
        return minArea;
    }
        
};