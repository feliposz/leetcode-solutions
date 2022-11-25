class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // rows
        for (int i = 0; i < 9; i++) {
            int digits[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
            for (int j = 0; j < 9; j++) {
                char c = board[i][j] ;
                if (c != '.') {
                    int d = c - '0' - 1;
                    if (digits[d])
                        return false;
                    digits[d] = 1;
                }
            }
        }

        // cols
        for (int i = 0; i < 9; i++) {
            int digits[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
            for (int j = 0; j < 9; j++) {
                char c = board[j][i];
                if (c != '.') {
                    int d = c - '0' - 1;
                    if (digits[d])
                        return false;
                    digits[d] = 1;
                }
            }
        }
        
        // squares
        for (int i = 0; i < 9; i++) {
            
            int sqRow = (i / 3) * 3;
            int sqCol = (i % 3) * 3;
            
            int digits[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
            for (int j = 0; j < 9; j++) {
                
                int row = j / 3;
                int col = j % 3;
                
                char c = board[sqRow + row][sqCol + col] ;
                if (c != '.') {
                    int d = c - '0' - 1;
                    if (digits[d])
                        return false;
                    digits[d] = 1;
                }
            }
        }

        return true;
    }
};