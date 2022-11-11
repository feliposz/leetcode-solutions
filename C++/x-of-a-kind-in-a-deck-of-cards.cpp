class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int,int> groups;
        
        for (int n: deck) {
            ++groups[n];
        }
        
        int x = INT32_MAX;
        for (auto g: groups) {
            if (x == INT32_MAX) {
                x = g.second;
            } else {
                x = gcd(x, g.second);
            }
        }
        
        for (auto g: groups) {
            if (g.second % x != 0) {
                return false;
            }
        }
        
        return x > 1;
    }
    
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};