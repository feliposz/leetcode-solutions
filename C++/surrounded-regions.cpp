class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (board[i][j] == 'O') {
                    tryCapture(board, i, j, m, n);
                }
            }
        }
    }

    void tryCapture(vector<vector<char>>& board, int i, int j, int m, int n) {
        set<vector<int>> visited;
        if (checkCapture(board, visited, i, j, m, n)) {
            for (auto p: visited) {
                board[p[0]][p[1]] = 'X';
            }
        }
    }

    bool checkCapture(vector<vector<char>>& board, set<vector<int>> &visited, int i, int j, int m, int n) {
        if (visited.count({i, j}) == 0 && board[i][j] == 'O') {
            visited.insert({i, j});
            if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
                return false;
            }
            return checkCapture(board, visited, i-1, j, m, n)
                && checkCapture(board, visited, i+1, j, m, n)
                && checkCapture(board, visited, i, j-1, m, n)
                && checkCapture(board, visited, i, j+1, m, n);
        }
        return true;
    }
};