class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image.size() > 0) {
            int orig = image[sr][sc];        
            ff(image, sr, sc, image.size(), image[0].size(), orig, color);
        }
        return image;
    }
    
    void ff(vector<vector<int>>& image, int sr, int sc, int rows, int cols, int orig, int color) {
        if ((image[sr][sc] == orig) && (image[sr][sc] != color)) {
            image[sr][sc] = color;
            if (sr > 0) ff(image, sr - 1, sc, rows, cols, orig, color);
            if (sc > 0) ff(image, sr, sc - 1, rows, cols, orig, color);
            if (sr < rows - 1) ff(image, sr + 1, sc, rows, cols, orig, color);
            if (sc < cols - 1) ff(image, sr, sc + 1, rows, cols, orig, color);
        }
    }
    
};