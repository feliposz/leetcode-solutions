class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        
        int a = (ax2 - ax1) * (ay2 - ay1);
        int b = (bx2 - bx1) * (by2 - by1);
        int c = 0;
        
        if (isRectangleOverlap(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2)) {
            int cx1 = max(ax1, bx1);
            int cx2 = min(ax2, bx2);
            int cy1 = max(ay1, by1);
            int cy2 = min(ay2, by2);
            c = (cx2 - cx1) * (cy2 - cy1);     
        }
        
        return a + b - c;
    }
    
    bool isRectangleOverlap(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
        return (x1 < x4) && (x3 < x2) && (y1 < y4) && (y3 < y2);
    }
};