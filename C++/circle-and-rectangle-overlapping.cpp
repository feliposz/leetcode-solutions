class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int x = xCenter;
        int y = yCenter;
        
        if (x < x1) {
            x = x1;
        } else if (x > x2) {
            x = x2;
        }
        
        if (y < y1) {
            y = y1;
        } else if (y > y2) {
            y = y2;
        }
        
        int d2 = (xCenter - x) * (xCenter - x) + (yCenter - y) * (yCenter - y);
        
        return d2 <= (radius * radius);
    }
};