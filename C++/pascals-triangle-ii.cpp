class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> triangle(rowIndex+1);
        
        for (int i = 0; i <= rowIndex; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    triangle[i].push_back(1);
                } else {
                    triangle[i].push_back(triangle[i-1][j-1] + triangle[i-1][j]);
                }
            }
        }
        
        return triangle.back();
    }
};