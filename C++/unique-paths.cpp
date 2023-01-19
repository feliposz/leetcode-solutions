class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> board;
        for (int i = 0; i < m; i++) {
            vector<int> row;
            for (int j = 0; j < n; j++) {
                row.push_back(1);
            }
            board.push_back(row);
        }
                    
        for (int i = 1; i < m; i++) {
            vector<int> row;
            for (int j = 1; j < n; j++) {
                board[i][j] = board[i-1][j] + board[i][j-1];
            }            
        }
                    
        return board[m-1][n-1];
    }
};