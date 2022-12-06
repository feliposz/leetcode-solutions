class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            p[i] = i + 1 ;
        }
        
        int x = 0;
        while (p.size() > 1) {
            x = (x + k - 1) % p.size();
            p.erase(p.begin() + x);
        }
        
        return p[0];
    }
};