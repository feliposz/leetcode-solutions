class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int rows = grid.size();
        int balls = grid[0].size();
        vector<int> ans;
        
        for (int b = 0; b < balls; b++) {
            int ball = b;
            for (int i = 0; i < rows; i++) {
                if ((grid[i][ball] == 1) && (ball+1 < balls) && (grid[i][ball+1] == 1)) {
                    ball++;
                } else if ((grid[i][ball] == -1) && (ball > 0) && (grid[i][ball-1] == -1)) {  
                    ball--;
                } else {
                    ball = -1;
                    break;
                }
            }
            ans.push_back(ball);
        }
        return ans;
    }
};