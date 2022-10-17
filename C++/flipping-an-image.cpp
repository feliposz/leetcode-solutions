class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int height = image.size();
        vector<vector<int>> ans(height);;
        
        for (int i = 0; i < height; i++) {
            int width = image[i].size();
            ans[i].resize(width);
            for (int j = 0; j < width; j++) {
                ans[i][j] = 1 - image[i][width - j - 1];
            }
        }
        
        return ans;
    }
};