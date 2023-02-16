class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> prev = grid;
        vector<vector<int>> curr = grid;
        
        int m = grid.size();
        int n = grid[0].size();
        
        int time = 0;
        
        bool changed = true;
        
        while (changed) {
            changed = false;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (curr[i][j] == 1) {
                        if (((i > 0) && (prev[i-1][j] == 2)) 
                            || ((i < m-1) && (prev[i+1][j] == 2)) 
                            || ((j > 0) && (prev[i][j-1] == 2)) 
                            || ((j < n-1) && (prev[i][j+1] == 2)))
                        {
                            curr[i][j] = 2;
                            changed = true;
                        }
                    }                
                }
            }
            time++;
            prev = curr;
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (curr[i][j] == 1) {
                    return -1;
                }
            }
        }
        return time-1;
    }
};