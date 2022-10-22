class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> cells;
        
        vector<vector<vector<int>>> byDist(rows + cols);
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int dist = abs(rCenter - i) + abs(cCenter - j);
                byDist[dist].push_back({i, j});
            }
        }
        
        for (auto &slot: byDist) {
            for (auto &cell: slot) {
                cells.push_back(cell);
            }
        }
        
        return cells;
    }
};