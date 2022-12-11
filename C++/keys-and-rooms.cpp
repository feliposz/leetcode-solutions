class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        set<int> visited;
        set<int> keys;
        
        visited.insert(0);
        for (int k: rooms[0]) {
            keys.insert(k);
        }
        
        bool changed = true;
        while (changed) {
            changed = false;
            for (int k: keys) {
                if (visited.count(k) == 0) {
                    visited.insert(k);
                    changed = true;
                    for (int k: rooms[k]) {
                        keys.insert(k);
                    }
                }
            }
        }
        
        return rooms.size() == visited.size();
    }
};