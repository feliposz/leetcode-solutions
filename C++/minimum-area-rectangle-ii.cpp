class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        int sz = points.size();
        
        double minArea = 0;
        bool first = true;
        
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                for (int k = j + 1; k < sz; k++) {
                    for (int l = k + 1; l < sz; l++) {
                        double area = rectangleArea(points[i][0], points[i][1],
                                    points[j][0], points[j][1],
                                    points[k][0], points[k][1],
                                    points[l][0], points[l][1]);
                        if ((area > 0) && (first || (minArea > area))) {
                            minArea = area;
                            first = false;
                        }                        
                    }
                }
            }
        }
        return minArea;
    }
        
    double rectangleArea(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
        vector<int> edges;
        double x = (x1 + x2 + x3 + x4) / 4.0;
        double y = (y1 + y2 + y3 + y4) / 4.0;
        
        double e1 = length(x, y, x1, y1);
        double e2 = length(x, y, x2, y2);
        double e3 = length(x, y, x3, y3);
        double e4 = length(x, y, x4, y4);
        
        if ((fabs(e1 - e2) < 0.001) && (fabs(e1 - e3) < 0.001) && (fabs(e1 - e4) < 0.001)) {
            return triangleArea(x1, y1, x2, y2, x3, y3) + triangleArea(x1, y1, x2, y2, x4, y4);
        } else {
            return -1;
        }        
    }    
    
    double triangleArea(int x1, int y1, int x2, int y2, int x3, int y3) {
        return fabs(0.5 * (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)));
    }
    
    double length(double x1, double y1, double x2, double y2) {
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }
};
