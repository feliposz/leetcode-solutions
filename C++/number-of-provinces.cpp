class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> cities(n);
        
        for (int i = 0; i < n; i++) {
            cities[i] = i;
        }
        
        while (true) {
            vector<int> prev = cities;
        
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (isConnected[i][j]) {
                        cities[i] = cities[j] = min(cities[i], cities[j]);
                    }
                }
            }
            
            if (prev == cities) {
                break;
            }
        }
        
        
        set<int> groups;
        for (int i = 0; i < n; i++) {
            groups.insert(cities[i]);
        }
        return groups.size();
    }
};