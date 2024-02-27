class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens,
                                            vector<int>& king) {

        // build an internal board representation
        bool board[8][8] = {};

        // place all queens in the board
        for (const auto& queen : queens) {
            board[queen[0]][queen[1]] = true;
        }

        vector<vector<int>> result;
        result.reserve(queens.size());

        // check all 8 directions
        for (int dy = -1; dy <= 1; dy++) {
            for (int dx = -1; dx <= 1; dx++) {

                // can't be both 0
                if (dx || dy) {
                    // starting from the king
                    int x = king[0] + dx, y = king[1] + dy;

                    // reached border?
                    while (x >= 0 && x < 8 && y >= 0 && y < 8) {
                        // find the first queen on that direction
                        if (board[x][y]) {
                            result.push_back({x, y});
                            break;
                        }
                        // move
                        x += dx;
                        y += dy;
                    }
                }
            }
        }
        return result;
    }
};