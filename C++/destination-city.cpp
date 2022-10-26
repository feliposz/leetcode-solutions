class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string, string> road;
        
        string city;
        for (vector<string> &p: paths) {
            road[p[0]] = p[1];
            city = p[0];
        }
        
        
        while (road.count(city) > 0) {
            city = road[city];
        }
        
        return city;
    }
};