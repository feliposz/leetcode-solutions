class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<int>> old;
        
        for (int i = 0; i < m + 2; i++) {
            vector<int> row;
            for (int j = 0; j < n + 2; j++) {
                if ((i > 0) && (i < m + 1) && (j > 0) && (j < n + 1)) {
                    row.push_back(board[i-1][j-1]);    
                }
                else
                {
                    row.push_back(0);
                }                
            }
            old.push_back(row);
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int live_neighbors = old[i][j] + old[i+1][j] + old[i+2][j]
                         + old[i][j+1] + old[i+2][j+1]
                         + old[i][j+2] + old[i+1][j+2] + old[i+2][j+2];
                if (old[i+1][j+1]) {
                    if (live_neighbors < 2) {
                        board[i][j] = 0;
                    } else if (live_neighbors > 3) {
                        board[i][j] = 0;
                    } else {
                        board[i][j] = 1;
                    }
                }
                else
                {
                    if (live_neighbors == 3)
                    {
                        board[i][j] = 1;
                    }
                    else
                    {
                        board[i][j] = 0;
                    }
                }
            }
        }
        
        
    }
};