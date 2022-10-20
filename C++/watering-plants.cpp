class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int can = capacity;
        int sz = plants.size();
        
        int moves = 0;
        for (int i = 0; i < sz; i++) {
            moves++;
            if (plants[i] > can) {
                moves += i * 2;
                can = capacity;
            }
            can -= plants[i];
        }
        
        return moves;
    }
};